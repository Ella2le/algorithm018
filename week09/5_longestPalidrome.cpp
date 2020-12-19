//
// Created by lewang on 12/20/20.
//


//暴力:
//先找所有子串中的回文子串,再拿出最长的返回

//
class Solution {
public:
    string longestPalindrome(string s) {
        int l = i, r = j;
        while(l < r) {
            if(s[l] == s[r]){
                l++;
                r++;
            }else{
                isPalidrome(s,l+1,r);
                isPalidrome(s,l,r-1);
            }
        }
        return s.substr(i,j);
    }
//    string isPalidrome(string& s, int i, int j){
//        int l = i, r = j;
//        while(l < r) {
//            if(s[l] == s[r]){
//                l++;
//                r++;
//            }else{
//                isPalidrome(s,l+1,r);
//                isPalidrome(s,l,r-1);
//            }
//        }
//        return s.substr(i,j);
//    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};
