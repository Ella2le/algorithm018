//
// Created by lewang on 10/23/20.
//
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hash.find(target - nums[i]);
            if(it != hash.end()) {
                return {it -> second, i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums {2,7,11,5};
    Solution test;
    vector<int> res;
    res = test.twoSum(nums,9);
    for(auto a:res) cout<< a;
    return 0;
}