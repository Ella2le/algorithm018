//
// Created by lewang on 12/11/20.
//

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //n是2的次幂,那么其有且仅有一个位为1
        if(n > 0) {
            return !(n & (n -1)); //清零最低位的1,如果是2的次幂那么得到的应该是0
        }
        else{
            return false;
        }


    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)return false;
        long x = n;
        //n是2的次幂,那么其有且仅有一个位为1
        //x & (-x) 取得最低位的1, 如果x仅有一个1,那么得到的数应该等于原来的x
        return  (x & (-x)) == x;
    }
};