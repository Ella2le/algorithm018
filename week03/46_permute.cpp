//
// Created by lewang on 11/7/20.
//
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
//dfs 回溯
//时间复杂度O(NxN!)
//空间复杂度O(NxN!)
class Solution {
    vector<vector<int>> permute(vector<int>& numd) {
        int len = nums.size();
        vector<vector<int>> res;

        if(len == 0) return res;

        vector<int> path;
        vector<bool> used (len,false);
        dfs(nums,len,0,path,used,res);
        return res;
    }

private:
    void dfs(vector<int> nums, int len,int depth, vector<int> path, vector<bool> used, vector<vector<int>> res) {
        //终止条件
        //排序的深度和数组的长度一样长了
        if(depth == len) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < len; i++) {
            if(used[i]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, len, depth+1, path, used, res);
        }
    }
};




//NB的动态数组,但是输出不是字典顺序
//时间复杂度O(NXN!)
//空间复杂度O(N)
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res,nums,0,int(nums.size()));
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        /*****************
         *res:用来存速返回结果
         *output是递归中间满足要求的一种排列
         *first 是当前排列的长度
        */
        //当前排列满足要求就返回output到res中
        if(first == len) {
            res.emplace_back(output);
            return;
        }
        for(int i= first; i < len; ++i) {
            //交换当前位置和i位置上的数
            swap(output[i],output[first]);
            dfs(res,output,first+1,len);
            //撤销之前的额操作,即回溯中重要的状态回退
            swap(output[i],output[first]);
        }
    }

};