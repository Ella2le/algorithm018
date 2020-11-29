//
// Created by lewang on 11/28/20.
//
#include <iostream>
#include <vector>

using namespace std;
//a. 最优子结构 opt[n] = best_of(opt[n-1],p[t[n-2],...]
//b. 储存中间状态 opt[i]
//c. 递推公式:
//opt[i][j] = opt[i+1][j] + opt[i][j+1] (且判断a[i][j]是否有障碍物)这种自下而上的感觉理解不能
//这题更倾向于 自上而下的: dp[i][j] = dp[i-1][j] + dp[i]dp[j-1]
//第一行和第一列都是111,因为他只能向右或者向左走
class Solution {
public:
    //另开一个数组,存储dp的状态
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i = 0; i < n; i++) dp[0][i] = 1;
        for(int j = 0; j < m; j++) dp[j][0] = 1;
        for(int i = 1; i < m; i ++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    //优化空间保留当前行和前一行
    int uniquePaths1(int m, int n) {
        vector<int> pre(n,1);
        vector<int> cur(n,1);
        for(int i = 1; i < m; i++) {
            for( int j = 1; j < n; j++) {
                cur[j] = cur[j-1] + pre[j];
            }
            pre = cur;
        }
        return pre[n-1];
    }
    //优化空间
    //只要保留一行的数据
    int uniquePaths2(int m, int n) {
        vector<int> cur(n,1);
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                cur[j] += cur[j-1];
            }
        }
        return cur[n-1];
    }
    //还有一个排列组合的方法
    //从左上到右下的路径中,向下和向左走到额步数是一定的,(0,0) --> (m-1,n-1),一定会向下走m-1步,向右走n-1步
    //所以一共走m+n-2步,其中选出m-1步是向下走的,Cm+n-2 m-1
    int uniquePaths3(int m, int n) {
        long res = 1;
        for(int i = 0; i < min(m-1,n-1); i++) {
            res*=m+n-2-i;
            res/=i+1;
        }
        return (int)res;
    }

};

int main(){
    Solution test;
    int m = 10, n =10;
    int res = test.uniquePaths3(m,n);
    cout<<res<<endl;
    return 0;
}