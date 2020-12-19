//
// Created by lewang on 12/19/20.
//
#include <iostream>
#include <string>
#include <vector>
using  namespace std;


class Solution {
public:
    string reverseWords(string s) {
        //Brute-force
        int len = s.size();
        //cout << len;
        bool flag = false;
        vector<string> ss;
        string temp;
        for(int i = 0; i < len; i++) {
            if(s[i] != ' '){
                temp += s[i];
                if(i == len - 1){

                    ss.push_back(temp);
                }


            }else if(s[i] == ' ' && !temp.empty())  { //|| (i = len - 1 &&!temp.empty())
                ss.push_back(temp);
                temp.erase(temp.begin(),temp.end());
            }else {
                continue;
            }

        }
        string res;

        for(int j = ss.size()-1; j >=0; j--) {
            res += ss[j];
            if(j > 0)  res +=' ';

        }
        return res;
    }


    //进阶用o(1)空间复杂度解决问题
    //即在原数组上进行操作
    string reverseWords1(string s) {
        int len = s.size();
        //reverse the whole string;
        for(int i = 0, j = len-1; i < j; i++, j--) {
            swap(s[i],s[j]);
        }
        cout << s.size() << ", |" << s <<"|"<<endl;
        //remove the extra space
        for(int i = 0; i < len; i++) {
            if(s[i]==' '&& (s[i + 1]==' '||(i+1) == s.size() || i == 0)){
                s.erase(i,1);
                i--;
            }
        }
        cout << s.size() << ", |" << s <<"|"<<endl;
        //reverse every word
        cout<<"s new lenght : " << s.size()<<endl;

        int l = 0,r = 0;
        for(int j = 0; j < s.size(); j++) {

            if(s[j] == ' ') {
                r = j - 1;
                while(l < r) {
                    swap(s[l],s[r]);
                    l++;
                    r--;
                }
                l = j + 1;
            }
            if(j == s.size()-1){
                r = j;
                while(l < r) {
                    swap(s[l],s[r]);
                    l++;
                    r--;
                }
                l = j + 1;
            }
        }

        return s;
    }
    //还可以用双指针,
    //c++ 有函数 reverse(), 可以实现快速反转,不用自己写循环
};


int main() {
    Solution test;
    string s = "                the sky is                  blue      ";
    cout<<"s length:" << s.size()<<endl;
    cout << s << endl;
    string res = test.reverseWords1(s);
    cout << "After reverse:\n" << res;

    return 0;
}