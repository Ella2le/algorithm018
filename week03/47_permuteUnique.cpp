//
// Created by lewang on 11/7/20.
//
#include <iostream>
#include <vector>
//回溯
//时间复杂度O(NxN!)
//空间复杂度O(N)

class Solution {
    //用来标记visited 的数
    vector<int> vis;

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx,vector<int>& perm) {
        //终止条件
        if(idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }

        for(int i = 0; i < (int)nums.size(); ++i) {
            //如果当前的数遍历过了,或者没遍历过但是和之前遍历过的数相等,跳过
            if(vis[i] || (i > 0 && nums[i] == nums[i -1] && !vis[i-1])){
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums,ans,idx + 1, perm);
            //状态重置,为回溯的重点
            vis[i] = 0;
            perm.pop_back();

        }
    }

    vectro<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(),nums.end());
        backtrack(nums,ans,0,perm);
        return ans;
    }
};