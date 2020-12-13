//
// Created by lewang on 11/29/20.
//
int maxProfit(vector<int>& prices) {
    int sum = 0;
    for(int i = 0; i < prices.size() - 1; i++){
        int temp = prices[i+1] - prices[i];
        if(temp) sum+=temp;
    }
    return sum;
}

