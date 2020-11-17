//
// Created by lewang on 11/15/20.
//
#include <iostream>
#include <vector>
#include <limits.h>
using  namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for(int i = 0; i < n -1; i++) {
            //如果当前能到的最远位置比当下的坐标序号大,
            if(maxPos >= i ) {
                //判断当前的坐标到的最远的地方和之前位置能到的最远的位置谁更远
                maxPos = max(maxPos, i+ nums[i]);
                //如果当前位置的下标就是能到的最远距离,就更新一部step,即就走到这了,找不到能走得更远的位置
                if(i ==end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
//时间复杂度O(n) 一个循环
//空间复杂度O(1),开了4个int;

};

int main(){
    Solution test;
    vector<int> nums {2,3,1,1,4};
    int res = test.jump(nums);
    cout<<res<<endl;

    return 0;

}