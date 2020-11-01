//思路：
//1.loop, count zero
//2. new array, loop
//3.index
//4.swap
//注意审题，面试的时候要向面试官确认数据的一些格式和应用场景
// Created by UPC on 2020/10/19.

//c++
class Solution {
    public void moveZeros(vector<int>& nums){
        //做题的时候要检查数据
        if (nums == null || nums.legth <= 1){
            return;
        }
        int j = 0 ;
        for  (int i = 0; i < nums.length;++i) {
            if(nums[i] != 0){
                nums[j] = nums[i];
                if(i != j){
                    num[i] = 0;
                }
                j++;
            }
        }
        std::cout<<nums<<std::endl;
    }
    //


};

//c++
#include <iostream>
#include <vector>
int main( ){
    Solution test;
    vector<int> nums(5)
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);
    std::cout<<nums<<std::endl;
    test.moveZeros(nums);
    return 0;
}
