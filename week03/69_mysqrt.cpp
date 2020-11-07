//
// Created by lewang on 11/7/20.
//
//二分查找
class Solution {
public:
    int mySqrt(int x) {
        //if(x < 2) return x;
        int left = 0;
        int right = x;
        int ans = -1;
        while(left <= right){
            long y = (left + right)/2;//注意这里要是long 和 long long 不然会有溢出的错误
            long long guess = y * y;
            if(guess <= x) {
                ans = y;
                left = y + 1;
            }else{
                right = y - 1;
            }

        }
        return ans;

    }
};

//牛顿逼近法`
