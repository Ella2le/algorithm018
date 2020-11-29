//
// Created by lewang on 11/29/20.
//

//用和三角形一样的数组储存dp
//实际上是一个n阶方阵的下三角
//[2]
//[3,4]
//[6,5,7]
//[4,1,8,3]



class Solution {
public:
    //time O(n^2)
    //space O(n^2)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n,vector<int>(n));
        //顶点需要注意,只有一个数
        f[0][0] = triangle[0][0];
        for(int  i = 1; i < n ; i++){
            //当j=0的时候,只能从上面"[i-1][j]走下来
            f[i][0] = f[i-1][0] + triangle[i][0];
            for(int j = 1; j < i; j++){
                //在i-1行"相邻"位置选择较小的数,加上当前位置三角形的数值
                f[i][j] = min(f[i-1][j-1], f[i-1][j]) + triangle[i][j];
            }
            //当j = i 的时候,是能从[i-1][j-1]走下来
            f[i][i] = f[i-1][i-1] + triangle[i][i];
        }
        return *min_element(f[n-1].begin(),f[n-1].end());
    }

    //优化空间,用两个长度为n的向量 O(2n)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(2,vector<int>(n));
        //顶点需要注意,只有一个数
        f[0][0] = triangle[0][0];
        for(int  i = 1; i < n ; i++){
            //当j=0的时候,只能从上面"[i-1][j]走下来
            int cur = i % 2; //也可以写 cur & 1
            int pre = 1 - cur;
            f[cur][0] = f[pre][0] + triangle[i][0];
            for(int j = 1; j < i; j++){
                //在i-1行"相邻"位置选择较小的数,加上当前位置三角形的数值
                f[cur][j] = min(f[pre][j-1], f[pre][j]) + triangle[i][j];
            }
            //当j = i 的时候,是能从[i-1][j-1]走下来
            f[cur][i] = f[pre][i-1] + triangle[i][i];
        }
        return *min_element(f[(n-1)%2].begin(),f[(n-1)%2].end());
    }

    //优化空间,用1个长度为n的向量 O(n)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        //顶点需要注意,只有一个数
        f[0] = triangle[0][0];
        for(int  i = 1; i < n ; i++){
            //每行最后一个元素只能从上面左边走下来
            f[i] = f[i-1] + triangle[i][i];
            for(int j = i - 1; j > 0; j--) {
                f[j] = min(f[j-1], f[j]) + triangle[i][j];
            }
            //每行第一个元素只能从上面走下来
            f[0] += triangle[i][0];
        }
        return *min_element(f.begin(),f.end());
    }

    //优化空间O(1),直接在原来的三角形数组上操作


};