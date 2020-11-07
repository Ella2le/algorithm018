//
// Created by lewang on 11/7/20.
//

#include <iostream>
#include <vector>

using namespace std;
//dfs
//递归

class Solution {
//方法一
//
public:
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return ans;

    }

private:
    void dfs(int cur,int n,int k) {
        //剪枝操作,如果数组中未遍历的数的长度加上当前temp的长度都小于k,后面的递归就不需要了
        //因为其如何都不能满足k
        if(temp.size() + (n -cur +1) < k) {
            return;
        }

        //如果temp度达到了k的要求,就把当前的组合存到答案中
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        //使用当前的这个数,把他放到temp中
        temp.push_back(cur);
        //移到下一个数去操作
        dfs(cur+1,n,k);
        //把当前的temp中选的数弹出去,去尝试没有组合过的数
        temp.pop_back();

        //不使用当前的这个数,不把cur push到temp中,直接跳到下一个
        dfs(cur + 1, n ,k);
    }

//字典序法
//todo



};

int main() {
    Solution test;
    int n = 4, k = 2;

    vector<vector<int>> res;
    res = test.combine(n,k);

    return 0;
}