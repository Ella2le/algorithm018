//
// Created by lewang on 10/26/20.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty()){
            return vector<int>();
        }
        //cout << *(nums1.cbegin()) << endl;

        unordered_set<int> m(nums1.cbegin(),nums1.cend());//Set 不储存重复的树!!
        //使用cbegin(),cennd() 而不是begin(),end(),是因为前者更安全
        for (auto n : m) cout << n << ","<< endl;
        vector<int> res;
        for (auto a : nums2) {
            if(m.erase(a) > 0){
                res.push_back(a);
            }
        }
        return res;
    }

};
//Runtime:4 ms, faster than 99.94% of C++ online submissions.
//Memory Usage:10.6 MB, less than 21.44% of C++ online submissions.
int main(){
    vector<int> nums1 {1,2,3,3,4,4,5};
    vector<int> nums2 {1,1,2,3,4,5,6};
    Solution test;
    vector<int> res;
    res = test.intersect(nums1,nums2);
    cout<<"-------haha-----------" << endl;
    for (auto a : res) cout << a << ",";
    cout << endl;
    return 0;
}