//
// Created by lewang on 10/25/20.
//
//Success:
//Runtime:4 ms, faster than 99.31% of C++ online submissions.
//Memory Usage:7.4 MB, less than 16.16% of C++ online submissions.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
            cout << s_char <<" "<< t_char<< endl;
            cout << s_char - 'a' <<" "<< t_char - 'a'<< endl;
            cout << cache[s_char - 'a'] <<endl;
            if(cache[s_char-'a']++ < 0) {
                size++;
            }
            cout << cache[s_char - 'a'] <<endl;
            cout << cache[t_char - 'a'] <<endl;
            if(cache[t_char-'a']-- > 0) {
                size++;
            }
            cout << cache[t_char - 'a'] <<endl;
            cout << "size: " << size <<endl;
        }
        if(size == s_len) {
            return true;
        } else {
            return false;
        }

    }
};

int main() {
    string s = "anagram";
    string t = "nawaram";
    Solution test;
    bool ans = test.isAnagram(s,t);
    cout << ans <<endl;
    return 0;
}