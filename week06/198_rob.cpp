//
// Created by lewang on 11/29/20.
//

//dp
//状态转移
//如果偷当前的房间,dp[i-2]+nums[i]
//如果不投当前的房间 dp[i-1]
//所以dp[i] = max(dp[i-2]+nums[i], dp[i-1])

//时间复杂度O(n)
//空间复杂度O(n)
int rob(vector<int>& nums) {
    if(nums.empty()) return 0;
    auto dp = nums;

    if(nums.size() == 1) return nums[0];

    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    }
    return dp[nums.size()-1];
}

//空间优化
int rob(vector<int>& nums) {
    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0];
    int first = nums[0], second = max(num[0], nums[1]);
    for(int i = 2; i < nums.size(); i++){
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}