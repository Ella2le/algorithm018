//
// Created by lewang on 12/12/20.
//
//用数组进行判断
//注意左上到右下的斜线满足,行下标与列下标之差相等, ex. (0,0),(3,3)
//左下到右上的斜线满足,行下标和列下标之和相等, ex,(3,0),(1,2)
#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

class Solution1 {
public:
    vector<vector<string>> solveNQueens(int n) {
        //这里一定要初始化不然会出错
        vector<vector<string>> res;
        vector<int> mainDiag(2 * n, 0);
        vector<int> subDiag(2 * n,0);
        vector<int> col(n,0);
        vector<string> ans(n,string(n,'.'));
        //从第0行开始排放Queen
        dfs(0,n,res,ans,col,mainDiag,subDiag);

        return res;
    }

private:
    void dfs(int row, int n, vector<vector<string>>& res,vector<string> ans, vector<int> col, vector<int> mainDiag,vector<int> subDiag){
        //terminator
        if(row == n){
            res.push_back(ans);
            return;
        }
        //process
        for(int i = 0; i < n; i++){
            //不同行不同列不同主副对角线
            if(!col[i] && !mainDiag[row - i + n] && !subDiag[row + i]) {
                //这里注意当前行标row,减去 当前的列标col的差值可能是负数,所以需要加上n,这里n相当于方阵的维
                col[i] = mainDiag[row - i + n ] = subDiag[row + i] = 1;//将不能放的位置都设置成1,标记为不能放置
                ans[row][i] = 'Q';//在这个位置放上Q
                //drill down
                dfs(row+1,n,res,ans,col,mainDiag,subDiag); //深度优先搜索-- 到下一行开始搜索
                //reverse state
                col[i] = mainDiag[row - i + n] = subDiag[row + i] = 0;//重置以便下次查找该行合适位置
                ans[row][i] = '.';
            }

        }

    }

};

//用位运算进行加速

class Solution2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        //这里一定要初始化不然会出错
        vector<vector<string>> res;
        vector<string> ans(n,string(n,'.'));
        //从第0行开始排放Queen
        dfs(0,n,res,ans,0,0,0);

        return res;
    }

private:
    void dfs(int row, int n, vector<vector<string>>& res,vector<string> ans, int col, int mainDiag,int subDiag){
        if(row == n){
            res.push_back(ans);
            return;
        }
        //process
        int bits = (~(col|mainDiag|subDiag))&((1<<n)-1);
        for(int i = 0, b = 1; i < n; ++i, b<<=1){
            //这里用了一个额外的ｉｎｔ　来标识　在ａｎｓ中那个位子放Ｑ
            int p = bits & -bits;
            if(b == p) {
                ans[row][i] = 'Q';
                bits = bits & (bits-1);
                dfs(row+1,n,res,ans,col|p,(mainDiag|p)<<1,(subDiag|p)>>1);
                ans[row][i] = '.';
            }

        }

    }

};


int main(){
    Solution2 test;
    vector<vector<string>> res = test.solveNQueens(4);
    return 0;
}