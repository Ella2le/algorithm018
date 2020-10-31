//
// Created by lewang on 10/28/20.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(const auto& x :arr) {
            map[x]++;
        }
        unordered_set<int> times;
        for(const auto& x: map){
            times.insert(x.second);
        }
        return times.size() == map.size();

    }
};

int main() {
    vector<int> arr {1,2};//{1,2,2,1,1,3,5};
    Solution test;
    bool res = test.uniqueOccurrences(arr);
    cout<<"result: "<<res;
    return 0;
}
