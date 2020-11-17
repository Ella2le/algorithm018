//
// Created by lewang on 11/15/20.
//
class Solution {

    int search2(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++) {
            if((nums[i+1] - nums[i]) < 0) {

                return nums[i+1];
            }

        }
        return nums[0];

    }
};
