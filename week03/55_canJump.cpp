//
// Created by lewang on 11/8/20.
//

//超时了
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool res = false;

        toNext(0, res, nums);
        return res;
    }

private:
    void toNext(int i, bool& res, vector<int> nums){
        if(i == int(nums.size() -1)){
            res = true;
            return;
        }
        //贪心算法,走当前可以走的最大步数

        int j = nums[i];

        while(j>0){
            i = i + j;
            if(i>= nums.size()-1 ){
                res = true;
                return;
            }else  if(i<nums.size() && nums[i] != 0){
                toNext(i,res, nums);
            }
            i = i - j;
            j--;

        }

    }
};
//贪心算法
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ri ghtmost = 0;
        for( int i = 0; i< n; i++) {
            if( i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if(rightmost >= n-1){
                    return  true;
                }
            }
        }
        return false;

    }
};