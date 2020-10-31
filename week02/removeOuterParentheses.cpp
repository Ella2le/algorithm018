//
// Created by lewang on 10/28/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeOuterParenteses(string s) {
        vector<char> res;
        string r;
        int level = 0;
//        res.push_back(s[0]);
        for (int i = 0; i <s.size(); i++){
            char c = s[i];
            if(c == ')') --level; //如果是右括号,当前出去一层括号,level-1
            if(level >= 1) res.push_back(c);
            if(c == '(') ++level;//如果是左括号,当前进去一层括号,level+1

        }
        for(auto rec :res){

            r = r + rec;
        }

        return r;
    }
    //如果要使用栈
    //什么情况下,某个括号要加入结果中? 非外层括号
    //怎么判断是非外层括号? 1.左括号加入前,栈不为空,2.右括号加入并消除括号,栈不为空
    string removeOuterParenteses2(string S) {
        stack<char> temp;
        string res;
        for(auto c : S){
            if(c == '('){
                if (!temp.empty()){
                    res = res + c;
                }
                temp.push(c);
            }
            if(c == ')'){
                temp.pop();
                if(temp.empty()){
                    res = res + c;
                }
            }
            return res;
        }
    }
};

int main() {
    string s = "(()())(())";
    Solution test;
    string res;
    res = test.removeOuterParenteses2(s);
    cout<<res<<endl;
    return 0;
}