//
// Created by lewang on 10/20/20.
//
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < int(nums.size() - 2); k++){
            if(nums[k] > 0) break;
            if(k > 0 && nums[k] == nums[k - 1]) continue;
            int i = k + 1, j = nums.size() - 1;
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                if(sum < 0){
                    while(i < j && nums[i] == nums[++i]);
                } else if (sum > 0) {
                    while(i < j && nums[j] == nums[--j]);
                } else {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[++i]);
                    while(i < j && nums[j] == nums[--j]);
                }
            }
        }
        return res;

    }
};
//Line 1034: Char 9: runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
//SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:9
/*---------------------------------------------------------------------------------
排序 + 双指针
        本题的难点在于如何去除重复解。

算法流程：
特判，对于数组长度 nn，如果数组为 nullnull 或者数组长度小于 33，返回 [][]。
对数组进行排序。
遍历排序后数组：
若 nums[i]>0nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 00，直接返回结果。
对于重复元素：跳过，避免出现重复解
        令左指针 L=i+1L=i+1，右指针 R=n-1R=n−1，当 L<RL<R 时，执行循环：
当 nums[i]+nums[L]+nums[R]==0nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,RL,R 移到下一位置，寻找新的解
        若和大于 00，说明 nums[R]nums[R] 太大，RR 左移
若和小于 00，说明 nums[L]nums[L] 太小，LL 右移
复杂度分析
        时间复杂度：O\left(n^{2}\right)O(n
2
)，数组排序 O(N \log N)O(NlogN)，遍历数组 O\left(n\right)O(n)，双指针遍历 O\left(n\right)O(n)，总体 O(N \log N)+O\left(n\right)*O\left(n\right)O(NlogN)+O(n)∗O(n)，O\left(n^{2}\right)O(n
2
)
空间复杂度：O(1)O(1)

作者：wu_yan_zu
        链接：https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution:
        def threeSum(self, nums: List[int]) -> List[List[int]]:

n=len(nums)
res=[]
if(not nums or n<3):
return []
nums.sort()
res=[]
for i in range(n):
if(nums[i]>0):
return res
if(i>0 and nums[i]==nums[i-1]):
continue
L=i+1
R=n-1
while(L<R):
if(nums[i]+nums[L]+nums[R]==0):
res.append([nums[i],nums[L],nums[R]])
while(L<R and nums[L]==nums[L+1]):
L=L+1
while(L<R and nums[R]==nums[R-1]):
R=R-1
L=L+1
R=R-1
elif(nums[i]+nums[L]+nums[R]>0):
R=R-1
else:
L=L+1
return res

        作者：wu_yan_zu
        链接：https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。