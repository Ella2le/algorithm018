//
// Created by lewang on 11/15/20.
//
#include <iostream>
#include <vector>>
#include <unordered_map>
#include <limits.h>
#include <cmath>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        auto it = m.find(target);
        return it->second;
    }
//不出意外地超时了
public:
    int left,right,i;
    int search2(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        for(i = 0; i < nums.size()-1; i++) {
            if(target == nums[i]) return i;
            if(target == nums[i+1]) return i+1;
            if((nums[i+1] - nums[i]) < 0) {

                if(target <nums[i]){
                    left = 0;
                    right = i;
                }
                if(target > nums[i+1]){
                    left = i +1;
                    right = (int)nums.size()-1;
                }
            }

        }

        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target){
                right = mid -1;
            }else{
                left = mid +1;
            }
        }
        return -1;

    }
    //Success:
    //Runtime:4 ms, faster than 92.04% of C++ online submissions.
    //Memory Usage:11.3 MB, less than 9.06% of C++ online submissions.

//------------国际版--光头哥的---看着费劲---------------------
    int search3(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while(lo < hi) {
            int mid = (lo + hi) / 2;

            double num = (nums[mid] < nums[0] == (target< nums[0]))
                         ? nums[mid]
                         : target < nums[0] ? -INFINITY : INFINITY;

            if(num < target)
                lo = mid + 1;
            else if( num > target)
                hi = mid;
            else return mid;
        }
        return -1;
    }
//    6:34 AM	info
//    Success:
//            Runtime:8 ms, faster than 62.83% of C++ online submissions.
//    Memory Usage:11.3 MB, less than 7.30% of C++ online submissions.
};

int main() {
    Solution test;
    vector<int> nums{4,5,6,7,0,1,2};
    int res = 0;
    res = test.search2(nums,3);
    cout<<res;
    return 0;
}
