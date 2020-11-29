//
// Created by lewang on 11/29/20.
//

//思路
//1. 搜索回溯
//暴力法,枚举所有可能,选硬币总数最小的方法
//用递归实现
//时间复杂化度,指数级 O(S^n)
//S是需要找零的总数,n是零钱面额数
//像是dfs
int getcoin(int idxCoin, vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    if(idxCoin < coins.size() &&  amount > 0) {
        int maxVal = amount / coins[idxCoin];
        int minCost = INT_MAX;
        for(int x = 0; x <= maxVal; x++) {
            if(amount >= x * coins[idxCoin]) {
                int res = getcoin(idxCoin+1, coins, amount - x * coins[idxCoin]);
                if(res != -1) minCost = min(minCost, res + x);
            }
        }
        return minCost = INT_MAX ? -1: minCost;
    }
    return -1;
}

int coinChange(vector<int>& coins, int amount) {
    return coinChange(0,coins,amout);
}

//方法2
//动态规划-自上而下
//状态转移方程
//f[s] = minf[s-ci] + 1 s.t. s - ci > 0
//f[s] = 0, when s = 0;
//f[s] = -1, when n =0
//时间复杂度O(Sn)
//空间 O(S)
//这个是从总额amount开始,一直减到总额为0;
vector<int> count;
int dp(vector<int>& coins, int rem) {
    if(rem < 0) return -1;
    if(rem == 0) return 0;
    if(count[rem - 1] != 0) return count[rem-1];
    int Min = INT_MAX;
    for(int coin:coins) {
        int res = dp(coins, rem - coin);
        if(res >= 0 && res < Min) {
            Min = res + 1;
        }
    }
    count[rem -1] = Min == INT_MAX ? -1 : Min;
    return count[rem - 1];
}
int coinChange(vector<int>& coins, int amount) {
    if(amount < 1) return 0;
    count.resize(amount);
    return dp(coins,amount);
}


//方法三动态规划, 自下而上
//这个是从总额0开始,一直加到目标
int coinChange(vector<int>& coins, int amount) {
    int max = amount + 1;
    vector<int> dp(amount + 1, max);
    dp[0] = 0;
    for(nt i = 1; i <= amount; ++i) {
        for(int j = 0; i < (int)coins.size(); ++j) {
            if(coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j] + 1]);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}



