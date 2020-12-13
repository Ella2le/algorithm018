//
// Created by lewang on 12/12/20.
//
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using  namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        if(s_len != t_len) return false;
        char s_char ;//= s[0];
        char t_char ;//= t[0];
        int size=0;
        vector<int> cache (26,0);
        for (int i = 0; i < s_len; ++i) {
            s_char = s[i];
            t_char = t[i];
            if(cache[s_char-'a']++ < 0) {
                size++;
            }
            if(cache[t_char-'a']-- > 0) {
                size++;
            }
        }
        if(size == s_len) {
            return true;
        } else {
            return false;
        }


    }
};