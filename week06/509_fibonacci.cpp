//
// Created by lewang on 11/28/20.
//
// F(0) = 0,   F(1) = 1
//F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //傻递归,up -> down
    //time O(2^n)
    //space O(n) 递归调用的深度,所用的栈的深度
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }

    //添加记忆搜索的循环
    //time O(n)
    //space O(n)
    int fib2(int n) {
        if(n <= 1) return n;
        vector<int> memo(n+1);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2; i < n; i++) {
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }

    //dp
    //time O(n)
    //space O(1)
    int fib2(int n) {
        if(n < 2) return n;
        int f1 = 0; f2 = 1; fn = 0;
        for(int i = 1; i < n; i++) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }

    //高贵的数学推理,不做强求
    int fib3(int n) {
        double phi = (sqrt(5) + 1) / 2;
        return round(pow(phi,n) / sqrt(5));
    }

};