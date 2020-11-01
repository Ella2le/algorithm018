//
// Created by lewang on 11/1/20.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>&nums,int k) {
        unordered_map<int,int> map;
        sort(nums.begin(),nums.end());
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it = map.begin(); it != map.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int) map.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }

//看不懂,但是submit可以通过, 学习不来....
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        using mapIter = unordered_map<int, size_t>::iterator;
        unordered_map<int,size_t> freqCount; // num -> frequency
        for(int num : nums){ ++freqCount[num]; }
        priority_queue<mapIter, vector<mapIter>, function<bool(mapIter, mapIter)>> topkHeap(
                [](mapIter lhs, mapIter rhs)
                {
                    return lhs->second > rhs->second; // build an min-heap!
                },
                vector<mapIter>()
        ); // frequency -> num
        for(mapIter iter = freqCount.begin(); iter != freqCount.end(); ++iter)
        {
            topkHeap.push(iter);
            if(topkHeap.size() > k){ topkHeap.pop(); } // remove the min value currently
        }
        // now heap hold the elements that elements less than them are all removed.
        vector<int> result(k);
        for(int i = k-1; i >= 0; --i)
        {
            mapIter iter = topkHeap.top();
            result[i] = iter->first;
            topkHeap.pop();
        }
        return result;
    }

};

int main(){
    vector<int> nums = {1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3};
    int k =2;
    Solution test;
    vector<int> res;

    res=test.topKFrequent(nums,k);
    for(auto i: res){
        cout << i<<endl;
    }


    return 0;
}