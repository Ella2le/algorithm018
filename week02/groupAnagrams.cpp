//
// Created by lewang on 10/26/20.
//
#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : m) {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }


    string strSort(string s) {
        int counter[26] = {0};
        for(char c: s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; ++c) {
            cout<<counter[c] <<" -> " << c+'a' <<" , " <<string(counter[c],c+'a')<<endl;
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};

int main(){
    vector<string> strs {"eat","five","telephone","ate","nat","beauty"};
    Solution test;
    string s = "letter";
    string t = test.strSort(s);
    cout<<t<<endl;
//    sort(strs.begin(),strs.end());
//    for(auto s: strs) cout<<s<<","<<endl;
    string tt = string(20,116);
    cout << tt;
    return  0;
}