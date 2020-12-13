//
// Created by lewang on 12/11/20.
//

int hammingWeight(uint32_t n) {
    //1. for loop
    int count = 0;
    uint32_t mask = 1;
    for(int i = 0; i < 32; i++) {
        if((n & mask) != 0 ) {
            count++;
        }
        mask = mask << 1;
    }
    return count;
}


class Solution {
public:
    int hammingWeight(uint32_t n) {
        //清零n的最低位 n = n&(n-1)
        int count = 0;
        while(n > 0) {
            count ++;
            n &= (n-1);
        }
        return count;
    }
};
//zb法,不用刻意记住,时间和空间都没有优势
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return (n>0) ? 1+ hammingWeight(n&(n-1)) : 0;
    }
};