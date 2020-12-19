//
// Created by lewang on 12/19/20.
//

//a. 暴力
//1) len(s的长度) mod 2k 余数为0
//2) len mod 2k 后 余数等于k,
//3) len mod 2k 后 余数大于k,前k个数还需要反转 (可以和1)&2)合并);
//4) len mod 2k 后 余数小于k,不用再反转

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int len = (int)s.size();
        int m = len % (2*k);
        int n = len / (2*k);

        for(int i = 0; i < n * 2* k; i += (2*k)) {
            cout << " p1 " << endl;
            cout<< i << endl;
            for(int l = i,r = i + k -1; l < r; l++,r--){
                cout<< " q1 "<<endl;
                cout << l <<" " << r << endl;
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
            }
        }
        cout << "fend" << endl;
        int left;
        if(m >= k) {
            left = k;
        }else {
            left = m;
        }
        for(int l = n*2*k,r = n*2*k + left -1; l < r; l++,r--){
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
        return s;

    }
};

int main(){
    Solution test;
    string s = "abcdefgh";
    string res;

    res = test.reverseStr(s,8);
    cout << res;
    return 0;
}