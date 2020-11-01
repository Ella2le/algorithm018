//
// Created by lewang on 11/1/20.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    vector<int> twoSum<vector<int> & nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size() ; ++i) {
            auto NeedNum = map.find(target - nums[i]);//在map中寻找想要的key,即target - nums[i]
            if(NeedNum != map.end()){ //如果找到了就返回
                return(it->second,i);
            }
            //如果没找到就把这个数和他对应的index放到map中
            map[num[i]] = i;//map的Key是nums的值,value是这个值在nums中的index
        }
        return {};
    }

};

int main(){

    return 0;
}