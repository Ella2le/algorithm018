//
// Created by lewang on 11/29/20.
//

//这个问题可以利用198分解一下
//拆为两个子数组一个有头,一个有尾,然后就可以用198的答案求解啦!!!
int rob(vector<int>& nums) {

    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0],nums[1]);
    int size = nums.size();
    vector<int>dp (size);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i = 2; i < size - 1; i++) {
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    }


    vector<int>dp1 (size);
    dp1[0] = nums[1];
    dp1[1] = max(nums[1],nums[2]);
    for(int i = 2; i < size - 1; i++) {
        dp1[i] = max(dp1[i-2] + nums[i+1], dp1[i-1]);
    }


    return max(dp[size - 2],dp1[size - 2]);
}

//[TODO] 还可以优化
//...