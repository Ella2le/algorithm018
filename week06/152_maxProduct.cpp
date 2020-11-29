//
// Created by lewang on 11/29/20.
//
//这题的关键在于讨论数值的正负,
//针对最后一个数的正负, 来前i-1个数是要求最大还是最小
//所以每个位置有两个状态即最大值,最小值
class Solution {
public:
    //时间 O(n)
    //空间 O(n)
    int maxProduct(vector<int>& nums) {
        vector<int> maxF(nums), minF(nums);
        for(int  i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i-1] * nums[i], max(nums[i], minF[i-1] * nums[i]));
            //前i-1的状态下的最小值*nums[i], min(nums[i], 前i-1状态下的最大值乘上当前的nums[i]
            minF[i] = min(minF[i-1] * nums[i], min(nums[i], maxF[i-1] * nums[i]));
        }
        return *max_element(maxF.begin(),maxF.end());
    }

    //空间优化
    //O(1)
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }

};
