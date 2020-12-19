//
// Created by lewang on 12/19/20.
//
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int len = S.size();
        int i = 0, j = len - 1;
        while(i < j) {
            char l = S[i];
            char r = S[j];

            if((int)(l-'A') < 0 || (int)(l- 'a') > 25 ||( (int) (l - 'a') < 0 && (int)(l - 'A' > 25)) ){
                i++;
                continue;
            }
            if ((int)(r-'A') < 0 || (int)(r- 'a') > 25 ||( (int) (r - 'a') < 0 && (int)(r - 'A' > 25)) ){
                j--;
                continue;
            }
            swap(S[i],S[j]);
            i++;
            j--;
        }
        return S;
    }
};
//c++ 自己的函数 isalpha 可以判断是否是字母,不用自己写if
//还可以用栈来反转字母,奇妙,自己没想到

int main(){
    Solution test;
    string s  = "a-bC-dEf-ghIj";
    //Expected:"j-Ih-gfE-dCba"
    cout << s << endl;
    string res = test.reverseOnlyLetters(s);
    cout << res <<endl;

    return 0;
}