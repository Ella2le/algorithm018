//
// Created by lewang on 11/5/20.
//

#include <iostream>
#include <vector>
#include <string>
#include <deque>
//这题用到回溯
//回溯: 是一种遍历算法,尝试用 深度优先算法 搜索所有结果
//和多层循环实现的暴力搜索相比较而言,回溯一般是有方向的搜索


//思路
//皇后的排放要求,
//1.不能在同一行
//2.不能在同一列
//3.不能在主对角线
//4.不能在负对角线

//记住皇后摆放的位置,则其所在的一个8连通的位置都不能放置皇后了
//小技巧:设置成员变量,可以减少函数中参数的列表,当然具体的使用需要参考要求的编程规范. --> 我不喜欢

class Solution {
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


