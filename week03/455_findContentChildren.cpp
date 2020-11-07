//
// Created by lewang on 11/8/20.
//
//双指针
//贪心先满足胃口大的?
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //if(s.back() < g.front()) return 0;
        //int len = min(g.size(),s.size());
        // if(s.front() > g.back()) return len;
        int res = 0;
        int j  = s.size() - 1;
        for(int i = g.size() - 1; i >= 0 ; i--) {
            if(j >= 0 && s[j] >= g[i]) {
                res ++;
                j--;
            }
        }
        return res;
    }
};
//先满足胃口小的
