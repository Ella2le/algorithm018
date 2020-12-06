//
// Created by lewang on 11/29/20.
//

//1.暴力法

int maxProfit(vector<int>& prices) {
    int n = (int)prices.size(), ans = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = i +1; j < n; ++j) {
            ans = max(ans, prices[j] - prices[i]);
        }
    }
    return ans;
}