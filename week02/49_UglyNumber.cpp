//
// Created by lewang on 11/1/20.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
//1. 暴力法 时间超标
    int nthUglyNumber(int n) {
        if(n<=6)  return n;
        int j=7,i=7;

        unordered_map<int,int> ugly {{1,1},{2,2},{3,3},{4,4},{5,5},{6,6}};

        while(i<=n){
            if(j%2==0 && ugly.find(j/2)!=ugly.end()){
                ugly.emplace(j,i);
                i++;
                j++;
                continue;
            }else if(j%3 == 0 && ugly.find(j/3)!=ugly.end()){
                ugly[j]=i;
                j++;
                i++;
                continue;
            }else if(j%5 == 0 && ugly.find(j/5)!=ugly.end()){
                ugly[j]=i;
                j++;
                i++;
                continue;
            }
            j++;

        }
        return j-1;
    }

    //
    int nthUglyNumber2(int n){
        int a= 0,b=0,c=0;
        //int[] dp =new int[n];
        vector<int> dp;
        dp[0] = 1;
        for(int i =1; i < n; i++){
            int n2 = dp[a]*2,n3 = dp[b] * 3, n5 = dp[c] = dp[c] * 5;
            dp[i] = min(min(n2,n3),n5);
            if(dp[i] == n2) a++;
            if(dp[i] == n3) b++;
            if(dp[i] == n5) c++;
        }
        return dp[n-1];
    }



};

int main(){
    Solution test;
    int n = 11;
    int res = test.nthUglyNumber(n);
    cout<<"res:"<<res;
    return 0;
}