//
// Created by lewang on 12/19/20.
//
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!= t.size()) return false;
        map<char,char> s2t;
        map<char,char> t2s;

        for(int i = 0; i < s.size(); i++){
            if((s2t.find(s[i])!=s2t.end() && s2t[s[i]] != t[i]) || ((t2s.find(t[i])!=t2s.end() && t2s[t[i]] != s[i]))) {
                return false;
            }else {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];

            }

        }
        return true;
    }

    //记录一个字符上次出现的位置，如果两个字符串中的字符上次出现的位置一样，那么就属于同构。
    //用一个数组来记录会比之前用map快很多!!!
    bool isIsomorphic1(string s, string t) {

        int preIndexOfs[256];
        int preIndexOft[256];
        for (int i = 0; i < s.size(); i++) {
            preIndexOfs[s[i]] = i + 1;
            preIndexOft[t[i]] = i + 1;
        }
        for( int i = 0; i < s.size(); i++) {
            if (preIndexOfs[s[i]] != preIndexOft[t[i]]) {
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution test;
    string a = "ab";
    string b = "cb";
    bool res = test.isIsomorphic1(a,b);
    cout <<res;

    return 0;
}