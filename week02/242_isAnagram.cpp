//
// Created by lewang on 11/1/20.
//
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s,string t){
        if(s.size() != t.size()) return false;
        unordered_map<int,int> cache;
        for (int i = 0; i < s.size(); i++) {
            char sc = s[i];//如果map中有就计数加一
            cache[sc - 'a']++;
        }
        for(int j = 0; j <t.size(); j++) {
            char tc = t[j];
            cache[tc - 'a'] --;//如果map中有就计数减一
            if(cache[tc -'a'] == 0){
                cache.erase(tc -'a');//如果map中对应字符计数为空 就将他删除
            }
        }
        if(cache.empty()){
            return true; //如果map为空了,则s和t刚好抵消了
        }else{
            return false;
        }
    }
};

int main(){
    string s = "anagram";
    string t = "nawaram";
    Solution test;
    bool ans = test.isAnagram(s,t);
    cout << ans <<endl;
    return 0;
}