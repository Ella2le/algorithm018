//
// Created by lewang on 12/12/20.
//

//课上推荐的最优解法
//dp
//状态转移方程
//p(x) = p(x & (x-1)) + 1
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1,0);
        for(int i = 1; i <= num; i++) {
            bits[i] += bits[i & (i - 1)] +1;
        }
        return bits;
    }
};
//体验了一下__builtin_popcount()和上面的方法其实是一样的
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1,0);
        for(int i = 1; i <= num; i++) {
            bits[i] = __builtin_popcount(i);
        }
        return bits;
    }
};



//超出时间限制??
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1,0);
        for(int i = 1; i <= num; i++) {
            int count = 0;
            while(i){
                count ++;
                i = i & (i-1);
            }
            bits[i] = count;
        }
        return bits;
    }
};

//dp
//状态转移方程
//p(x+b) = p(x)+1,b=2的m次幂
//超出时长??
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans (num+1,0);
        int i = 0, b = 1;

        while(b <= num){
            while(i < b && i+b <= num){
                ans[i+b] = ans[i] +1;
                ++i;
            }
            i = 0;
            b << 1;
        }
        return ans;

    }
};

//dp
//状态转移方程
//p(x) = p(x/2) + (x mod 2)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1,0);
        for(int i = 1; i <= num; i++) {
            bits[i] = bits[i>>1] + (i & 1);
        }
        return bits;
    }
};




