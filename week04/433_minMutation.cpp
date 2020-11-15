//
// Created by lewang on 11/10/20.
//
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(),bank.end());
        if(!dict.count(end)) return -1;
        unordered_set<string> bset, eset, *set1,*set2;
        bset.insert(start),eset.insert(end);

        int step = 0, n = start.size();

        while(!bset.empty() && !eset.empty()) {
            if(bset.size() <= eset.size()) {
                set1 = &bset,set2 = &eset;
            }else{
                set2 = &bset, set1 = &eset;
            }
            unordered_set<string> tmp;
            step ++;
            for(auto itr = set1->begin();itr != set1->end(); ++itr) {
                for(int i = 0; i < n; ++i) {
                    string dna = *itr;
                    for(auto g : string("ATGC")) {
                        dna[i] = g;
                        if(set2->count(dna)) return step;
                        if(dict.count(dna)) {
                            tmp.insert(dna);
                            dict.erase(dna);
                        }
                    }
                }
            }
            *set1 = tmp;
        }
        return -1;
    }
};

int main(){
    Solution test;
    string s1 = "AATTUGG";
    string s2 = "AATAUGG"
    vector<string> bank {"AATAUGG"};
    int res = test.minMutation(s1,s2,bank);
    return 0
}