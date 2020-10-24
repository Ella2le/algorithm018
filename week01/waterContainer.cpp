//
// Created by UPC on 2020/10/19.
//
//双指针
#include <vector>
using namespace std;
class Solution{
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int res = 0;
        while (l < r) {
            int area = min(height[l],height[r]) * (r - l);
            res = max(res , area);
            if(height[l] < height[r]){
                ++l;//l++;
            } else{
                --r;//r--也可以
            }
        }
        return res;
    }
};
//执行用时：
//48 ms
//, 在所有 C++ 提交中击败了
//13.96%
//的用户
//内存消耗：
//17.8 MB
//, 在所有 C++ 提交中击败了
//5.01%
//的用户
//--------------------------------------------------------------i----------

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = 0, area=0;
        while (l < r)//<=
        {
            int h = min(height[l], height[r]);
            res = max(res,h*(r-l));
            while (height[l] <= h && l < r) l++;
            while (height[r] <= h && l < r) r--;
        }
        return res;
    }
};
//执行用时：
//32 ms
//, 在所有 C++ 提交中击败了
//18.49%
//的用户
//内存消耗：
//17.8 MB
//, 在所有 C++ 提交中击败了
//5.01%
//的用户