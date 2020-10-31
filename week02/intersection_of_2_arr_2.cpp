//
// Created by lewang on 10/26/20.
//

//自己的写法,但是显示内存有问题
#include <iostream>
#include <vector>
//#include <bits/unordered_map.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res;
        vector<int> cache {10,0};
        if(len1 == 0 || len2 == 0) return res;

        for (int i = 0; i < len1; ++i) {
            cout << i << endl;
            int temp = nums1[i];
            if(cache[temp - 0]++ < 0){
                res.push_back(temp);
            }
        }
        for (int j = 0; j < len2; ++j) {
            cout << j << endl;
            int temp = nums2[j];
            if(cache[temp - 0]-- > 0){
                res.push_back(temp);
            }
        }
        return res;
    }

//较快的解法
    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2){
        vector<int> res;
        unordered_map<int,int> umap;
        for (int num : nums1) {
            umap.at(num)++;
        }
        for (int num : nums2) {
            if(umap[num] > 0) {
                res.push_back(num);
                umap[num]--;
            }
        }
        return res;
    }

//Runtime:4 ms, faster than 99.68% of C++ online submissions.
//Memory Usage:10.8 MB, less than 6.65% of C++ online submissions.

//
    vector<int> intersect3(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty()){
            return vector<int>();
        }
        unordered_map<int,int> cache;
        for(int i : nums1) {
            cache[i]++;
        }
        vector<int> out;
        for(int i : nums2) {
            if (cache[i]-- > 0){
                out.push_back(i);
            }
        }
        return out;
    }
//Success:
//Runtime:12 ms, faster than 72.72% of C++ online submissions.
//Memory Usage:10.7 MB, less than 16.60% of C++ online submissions.
};


int main(){
    vector<int> nums1 {1,2,4,4,6};
    vector<int> nums2 {2,3,4,2,4};
    Solution test;
    vector<int> res;
    res = test.intersect(nums1,nums2);
    for(auto n : res) cout<< n <<',';

    return 0;
}