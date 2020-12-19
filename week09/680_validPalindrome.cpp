//
// Created by lewang on 12/19/20.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.size();
        bool isSwaped = false;
        for(int i = 0, j = len - 1; i < j; i++, j--) {
            cout << s[i] << " " << s[j]<<endl;
            if(s[i] == s[j]){
                cout << "P1  i= " << i << " j = "<<j << endl;
                continue;
            }else if(!isSwaped){
                int l = i + 1;
                int r = j - 1;
                //if(l == r)return true;
                isSwaped = true;
                cout << "P2  i= " << i << " j = "<<j << endl;
                if(s[l] == s[j]){
                    i++;
                    cout << "P2-1  i= " << i << " j = "<<j << endl;
                    continue;

                }else if(s[i] == s[r]){
                    j--;
                    cout << "P2-2  i= " << i << " j = "<<j << endl;
                    continue;
                }
                else {
                    cout << "P3  i= " << i << " j = "<<j << endl;
                    return false;
                }
            }else if(isSwaped && s[i] != s[j]) {
                cout << "P4  i= " << i << " j = "<<j << endl;
                return false;
            }

        }
        return true;
    }
};
//暴力的时候有问题

class Solution2 {
public:
    bool palindrome(const std::string& s, int i, int j)
    {
        for ( ; i < j && s[i] == s[j]; ++i, --j);
        return i >= j;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        for ( ; i < j && s[i] == s[j]; ++i, --j);
        return palindrome(s, i, j - 1) || palindrome(s, i + 1, j);
    }
};

int main() {
    Solution test;
//    cout << " i= " << i << " j = "<<j << endl;
    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";

    bool res = test.validPalindrome(s);
    cout << s[21] << " " << s[80] << endl;
    cout << res;
    return 0;
}