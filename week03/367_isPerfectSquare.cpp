//
// Created by lewang on 11/7/20.
//

//偷懒用api中de函数

class Solution{
public:
   bool isPerfectSquare(int num) {
        double k = sqrt(num);
        if(k != int(k){
            return false;
        }else{
            return true;
        }
    }
};

//正经写
//二分查找
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0) return false;
        if(num < 2) return true;

        int left = 2,right = num/2;

        while(left <= right){
           //这里注意是x = (left + right)/2
            long  x = (left + right)/2;
            long long guess = x * x;
            if(guess == num) return true;
            if(guess > num){
                right = x - 1;
            }else{
                left = x + 1;
            }


        }
        return false;

    }
};

//梯度下降法
bool isPerfectSquare(int num) {
    if(num < 0) return false;
    if(num < 2) return true;

    long long x = num/2;//注意这里写int会溢出

    while(x*x > num){
        x = (x + num/x)/2;

    }
    return x*x ==num;

}

