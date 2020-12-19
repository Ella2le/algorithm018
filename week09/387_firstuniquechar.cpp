//
// Created by lewang on 12/19/20.
//
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // int res = -1;
        unordered_map<char,int> m;
        for(int i = 0; i < s.size(); ++i) {
            m[s[i]] += 1;
        }
        for(int i = 0; i < s.size(); ++i) {
            if(m[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main(){
    Solution test;
    string s = "hahafirst";
    int res = test.firstUniqChar(s);

    cout << res << endl;
    return 0;
}