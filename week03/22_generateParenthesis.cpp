//
// Created by lewang on 11/3/20.
//


#include <iostream>
#include <vector>
#include <string>

using namespace std;
//左边括号随时可以加,只要不超标
//右括号必须出现在左括号后,且左括号的个数要大于右括号的个数(加之前)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s ;
        generate(0,0,n,s,res);

        return res;
    }
private:
    void generate(int left, int right,int n,string s,vector<string>& res) {
        //左括号和右括号用完了就达到了终止条件
        //terminator
       // vector<string> res;
        //if(rc>lc || lc > n || rc > n) return;
        if(left == n && right == n){
            res.push_back(s);
            //cout<<s<<endl;
        }
       // cout<<s<<endl;
        //drill down
        if(left < n){
            //left++;
            generate(left+1,right,n,s+"(",res);
        }
        if(left > right) {
            //right++;
            generate(left,right+1,n,s+")",res);
        }

    }

};

int main(){
    Solution test;
    int n = 3;
    vector<string> res;
    res = test.generateParenthesis(n);
    for(auto c : res) cout<<c<<endl;
    return 0;
}