//
// Created by lewang on 11/29/20.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    //和obstacleGrid一样大的dp
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(row == 0 || col == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1) return 0;
        vector<vector<int>>dp(row,vector<int>(col,0));

        for(int  i = 0; i < col; i++){
            if(obstacleGrid[0][i] == 0) dp[0][i] = 1;
            if(obstacleGrid[0][i] == 1) break;
        }
        for(int j = 0; j < row; j++) {
            if(obstacleGrid[j][0] == 0) dp[j][0] = 1;
            if(obstacleGrid[j][0] == 1) break;
        }

        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(obstacleGrid[i][j] == 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            }
        }
        return dp[row-1][col-1];
    }

    //空间优化
    //只用两个向量
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if (row == 0 || col == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) return 0;
        vector<int> cur(col, 0);
        vector<int> pre(col, 1);
        bool flag = true;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if(i == 0 ){
                    if(!obstacleGrid[i][j] && flag) cur[j] = 1;
                    if(obstacleGrid[i][j]) {
                        cur[j] = 0;
                        flag = false;
                    }
                }
                if(j == 0){
                    if(!obstacleGrid[i][j] && pre[j]) cur[j] = 1;
                    if(obstacleGrid[i][j]) cur[j] = 0;
                }

                if (i > 0 && j > 0) {
                    if (!obstacleGrid[i][j]) cur[j] = cur[j - 1] + pre[j];
                    if (obstacleGrid[i][j]) cur[j] = 0;
                }

                pre = cur;
            }
        }

        return cur[col - 1];
    }

    //空间优化
    //只用1个向量
    //[TODO]在i==0 || j == 0 的时候的处理有点问题
    int uniquePathsWithObstacles3(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if (row == 0 || col == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) return 0;
        vector<int> cur(col, 1);
        bool f = true;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0) {
                    if (obstacleGrid[i][j] == 0 && f &&cur[j]) {
                        cur[j] = 1;
                    } else {
                        cur[j] = 0;
                    }
                    if (obstacleGrid[i][j] == 1 && f) {
                        cur[j] = 0;
                        f = false;
                    }
                }

                if (i > 0 && j > 0) {
                    if (obstacleGrid[i][j] == 0) cur[j] += cur[j - 1];
                    if (obstacleGrid[i][j] == 1) cur[j] = 0;
                }
            }
        }
        return cur[col - 1];
    }
};

int main() {
    Solution test;

    return 0;
}