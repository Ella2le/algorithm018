//
// Created by lewang on 11/1/20.
//

//给定一个字符串数组,将字母异位词,组合在一起.字母异位词指字母相同,但排列不同的字符串.

#include <iostream>
#include <vector>
#include <string>

using namesapce std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string sorted_str;
        unordered_map<string,vector<string>> map;
        //将排好序的words作为map的key,因为如果是异位词,排序后大家长一样的
        for (auto t:strs) {
            sorted_str = t;
            sort(sorted_str.begin(),sorted_str.end());
            map[sorted_str].push_back(t)
        }
        vector<vector<string>> res;

        for(auto t : map){
            res.push_back(t.second);
        }
        return res;
    }

};

int main(){


    return 0;
}