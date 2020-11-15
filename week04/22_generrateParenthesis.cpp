//
// Created by lewang on 11/12/20.
//

//思路
//暴力递归生成所有的可能然后剔除不合理的,返回正确结果
//时间复杂度 O(2^2n * n)


//广度优先搜索找出所有的排序,然后剔除不合理的,返回正确结果

//深度优先搜索
//时间复杂度 O(4^n/ sqrt(n)),在回溯过程中每个答案需要O(n)的时间复制到答案数组中
//空间复杂福: O(n) 除了答案数组,我们所需要的空间取决于递归栈的深度,每一层递归函数需要O(1)的空间,最多递归2n层.因此需要空间复杂度为O(n)


#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParathesis(int n) {
        vector<string> res;
        if(n==0) return res;
        string s;
        dfs(n,res,s,0,0);
        return res;
    }

private:
    void dfs(int n,vector<string> &res,string s, int left, int right) {
            if(left == n && right == n) {
                res.push_back(s);
            }
            if(left < n) {
                dfs(n,res,s+'(',left+1,right);
            }
            if(left > right){
                dfs(n,res,s+')',left,right+1);
            }
    }


};

int main(){
    Solution test;
    vector<string> res;
    res = test.generateParathesis(3);
    for(auto s: res) cout<<s<<endl;
    return 0;
}

