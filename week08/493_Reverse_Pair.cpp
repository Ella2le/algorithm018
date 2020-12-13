//
// Created by lewang on 12/12/20.
//
//1.两个嵌套循环 O(n^2)

//2. merge-sort O(NlogN)

//3. 树状数组 O(NlogN)
#include <iostream>
#include <vector>
#include <random>
#include <string.h>
#include <algorithm>

using  namespace std;
//
//class Solution1{
//public:
//    int reversePair(vector<int> nums){
//        return mergeSort(nums,0,nums.size() - 1);
//    }
//private:
//    int mergeSort(vector<int> nums, int s, int e) {
//        if(s >= e) return 0;
//        int mid = s + ((e - s)>>1);
//        int cnt = mergeSort(nums, s, mid) + mergeSort(nums, mid+1, e);
//        for(int i = s; j = mid + 1; i <= mid; i++) {
//            while(j <= e && nums[i]/2.0 > num[j]) j++;
//            cnt += j - (mid + 1);
//        }
//        sort(nums.begin(),nums.end());//这里偷懒使用sort把整个算法的时间复杂度从nlogn变成nlogn * logn
//        return cnt;
//    }
//};
//自己写merge就是之前的模板里的
//public class Solution {



//}



class Solution2 {
public:
    int reversePairs(vector<int> nums){
        if(nums.empty() || nums.size() == 0) return 0;
        return  mergeSort(nums,0,nums.size() - 1);
    }
private:
    int mergeSort(vector<int> nums, int l, int r) {
        if(l >= r) return 0;
        int mid = (r-l)/2 + 1;
        int count = mergeSort(nums, l, mid) + mergeSort(nums, mid+1, r);
        vector<int> cache (r-l+1, 0);
        int i = l, t = l, c =0;
        for(int j = mid +1; j <= r; j++, c++) {
            cout<<j<<" ";
            while(i <= mid && nums[i] <= 2*(long)nums[j]) i++;
            while(t <= mid && nums[t] < nums[j]) cache[c++] = nums[t++];
            cache[c] = nums[j];
            count += mid - i + 1;
        }
        while (t <= mid) cache[c++] = nums[t++];
        //memcpy(nums,cache,sizeof(cache));
        //System.arraycopy(cache,0 , nums, l,r-l+1);
        for(int p = 0; p < cache.size(); p++) {
            nums[l + p] = cache[p];
        }
        return count;
    }
};
class Solution3 {
public:
    int reversePairs(vector<int> nums){
        if(nums.empty()) return 0;
        return  mergeSort(nums,0,(int)nums.size() - 1);
    }
private:
    int mergeSort(vector<int> nums, int l, int r) {
        if(l >= r) return 0;
        int mid = 1+((r-1)>>1);
        int count = mergeSort(nums, l, mid) + mergeSort(nums, mid+1, r);

        vector<int> cache (r-l+1, 0);
        int i = l, j = mid + 1, k = 0, p = mid + 1;

        while(i <= mid) {
            while(p <= r && nums[i] > (long)2*nums[p]) p++;
            count += p - (mid + 1);

            while(j <= r && nums[i] >= nums[j]) cache[k++] = nums[j++];
            cache[k++] = nums[i++];
        }
        while (j <= r) {
            cache[k++] = nums[j++];
        }

        return count;
    }
};
class Solution{
public:
    int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
        if(end - begin <= 1) {
            return 0;
        }
        auto mid = begin + (end - begin)/2;
        int count = sort_and_count(begin,mid) + sort_and_count(mid,end);
        for(auto i = begin, j = mid; i != mid; ++i) {
            while(j != end and *i>2L * *j) {
                ++j;
            }
            count += j -mid;
        }
        inplace_merge(begin,mid,end);
        return count;
    }
    int reversePair(vector<int>& nums) {
        return sort_and_count(nums.begin(), nums.end());
    }
};



int main() {
    random_device a;
    uniform_int_distribution<int> u(1,100);
    vector<int> arr;
    for(int  i = 0; i < 10; i++){
        int x = u(a);
        cout<<x<<" ";
        arr.push_back(x);
    }

    Solution3 test;
    int r = test.reversePairs(arr);

    cout<<"\n"<<r;
    return 0;
}