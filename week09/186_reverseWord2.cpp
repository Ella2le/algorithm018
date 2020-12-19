//
// Created by lewang on 12/19/20.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void reverseWords(vector<char>& s) {
        int len = s.size();
        //cout << len;
        bool flag = false;
        vector<string> ss;
        string temp;
        for(int i = 0; i < len; i++) {
            if(s[i] != ' '){
                temp += s[i];
                if(i == len - 1){
                    ss.push_back(temp);
                }
            }else if(s[i] == ' ' && !temp.empty())  { //|| (i = len - 1 &&!temp.empty())
                ss.push_back(temp);
                temp.erase(temp.begin(),temp.end());
            }else {
                continue;
            }

        }
        s.erase(s.begin(),s.end());
        for(int j = ss.size()-1; j >=0; j--) {
            for(int i = 0; i < ss[j].size(); i++ ){
                char temp = ss[j][i];
                s.push_back(temp);
            }
            if(j > 0) s.push_back(' ');

        }
        //return res;

    }
};

//进阶用o(1)空间复杂度解决问题
//即在原数组上进行操作