//
// Created by lewang on 11/29/20.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for(const auto &x : nums) {
            pre = max(x, pre + x);
            maxAns = max(maxAns,pre);
        }
        return maxAns;
    }

    //神奇的线段树,期待讲解
    struct Status {
        int lSum,rSum,mSum,iSum;
    };

    Status pushUp(Status l, Status r){
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum,l.iSum + r.lSum);
        int rSum = max(r.rSum,r.rSum + r.iSum);
        int mSum = max(max(l.mSum,r.mSum),l.mSum+r.mSum);
        return (Status) {lSum.rSum, mSum, iSum};
    }

    Status get(vector<int> &a, int l, int r) {
        if(l == r) return (Status) {a[1],a[1],a[1],a[1]};
        int m = (l + r) >> 1;
        Status lSub = get(a, 1, m);
        Status rSub = get(a, m+1, r);
        return pushUp(lSub,rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(num, 0 , nums.size() -1).mSum;
    }
};