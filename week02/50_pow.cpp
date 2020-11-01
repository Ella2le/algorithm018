//
// Created by lewang on 11/1/20.
//

//暴力法 会超时
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.;
        double a = abs(n);
        double p = 1.;
        for (int i = 0; i < a; ++i) {
            p*=x;
        }


        if(n>0){
            return p;
        }else{
            return double(1/p);
        }

    }

    //快速幂
    double quickMul(double x, long long N){
        if(N == 0){
            return 1.0;
        }
        double y = quickMul(x,N/2);
        return N%2 == 0? y*y: y*y*x;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N>=0 ? quickMul(x,N) : 1.0/quickMul(x,-N);
    }
};