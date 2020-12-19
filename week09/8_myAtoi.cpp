//
// Created by lewang on 12/20/20.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
// 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
// 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
// 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。
// 在任何情况下，若函数不能进行有效的转换时，请返回 0 。
// 提示：
// 本题中的空白字符只包括空格字符 ' ' 。
// 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231, 231 − 1]。如果数值超过这个范围，请返回 INT_MAX (231
// − 1) 或 INT_MIN (−231) 。
using namespace std;
//我的暴力解法
//[TODO]边界问题还是比较难考虑全的,后面可以再完善一下
class Solution {
public:
    int myAtoi(string s) {
        //排除s为空
        if(s.empty()) return 0;
        int res = 0;
        int sign = 1;
        int limit = 0;
        //移除开头的空字符
        unsigned long spacePos=0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                spacePos = (unsigned long)i;
                break;
            }

        }
        s.erase(0,spacePos);
        cout <<s<<endl;


        //排除第一个非空字符不合法
        if(s[0] != '-'&&s[0] != '+'  && s[0] - '0' > 9 && s[0] - '0' < 0 ) {
            cout<<s[0] - '0'<<endl;
            cout << "the first char "<<s[0]<<" is illegal"<<endl;
            return 0;
        }


        for(int i = 0; i < s.size(); i++) {
           // cout << i << ": " << s[i]<<endl;
            if(s[0] == '-' ) {
                sign = -1;
                continue;
            }
            if(s[0] == '+'){
                continue;
            }
            if(s[i] - '0' < 9 && s[i] - '0' > 0){
                res = res*10 + int(s[i] - '0');
                limit++;
                if(limit > 31)
                cout <<res <<endl;
            }else {
                break;
            }

        }

        return res*sign;
    }
};
//官方自动机
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution2 {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};



int main() {
    Solution test;
    string s = "      21432";
    int res = test.myAtoi(s);
    cout<<res;
    return 0;
}