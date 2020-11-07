//
// Created by lewang on 11/7/20.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //vector<int> diff;// (prices.size()-1,0);
        int sum = 0;
        for(int i = 0; i< int(prices.size()-1); i++) {
            int diff = prices[i+1] - prices[i];
            if(diff > 0) {
                sum += diff;
            }
        }
        return sum;
    }
};