
//
// Created by lewang on 11/29/20.
//

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+3);
        dp[1]=1;//爬到1阶有一种方法
        dp[2]=2;//爬到2阶有2种方法
        //爬到n阶的方法等于,爬到你n-1和n-2的方法的和
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};