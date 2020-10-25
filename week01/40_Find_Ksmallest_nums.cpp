//
// Created by lewang on 10/25/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //先排序,再依次输出最小的几个
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int length = arr.size();
        vector<int> res;
        int curr = arr[0];
        sort(arr.begin(),arr.end());
        for (int i = 0; i < k; ++i) {
            //int temp = min(arr);
            int out = arr[i];
            res.push_back(out);
        }
        return res;
    }
    //Runtime:88 ms, faster than 59.50% of C++ online submissions.
    //Memory Usage:18.9 MB, less than 50.67% of C++ online submissions.

    //----------------------------------------------------------------------
    //堆


    //快排思想

};

int main(){
    vector<int> arr = {1,5,4,3,2,0};

    vector<int> res;
    int k=2;
    Solution test;
    res = test.getLeastNumbers(arr,k);
   for(auto j:res) cout<< j <<",";
   cout<<endl;

    return 0;
}