//
// Created by lewang on 10/24/20.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//暴力解法
//guess.find_first_of (secret)
//对比index
//嵌套循环
// 时间复杂度O(n^2)
class Solution{
public:
    string getHint(string secret, string guess) {
        int size = secret.size();
        int x,y;
        string ans = "AB";
        cout<<"secret size" << size <<endl ;
        for (int i = 0; i < (2*size -1); i++ ) {
            cout<< "now" << i << endl;
            if(i < size) {
                string str1 = secret.substr(size - i - 1, i + 1);
                string str2 = guess.substr(0, i + 1);
                int str1_num, str2_num;
                str1_num = stoi(str1);
                str2_num = stoi(str2);
                cout << str1_num << " && " << str2_num << endl;
                int flag = str1_num - str2_num;
                cout<<flag<<endl;
            } else {
                string str1 = secret.substr(0, i-size+1);
                string str2 = guess.substr(i-size, i-size+1);
                int str1_num, str2_num;
                str1_num = stoi(str1);
                str2_num = stoi(str2);
                cout << str1_num << " && " << str2_num << endl;
                int flag = str1_num - str2_num;
                cout<<flag<<endl;
            }


        }
        return ans;
    }
    string getHint2(string secret, string guess) {
        int len = secret.size();
        vector<int> cache(10, 0);
//        for(auto i:cache) cout<<i <<"," ;
        int x = 0, y = 0;
        for (int i = 0; i<len; i++){
            cout << "now " << i<<endl;
            char cs = secret[i];
            char cg = guess[i];
            cout << "secret char: " << cs << endl;
            cout << "guess char: " << cg <<endl;

            if(cs == cg){
                x++;
            } else {

                cout<<cs<<endl;
                cout<< cache[cs - '0']<<endl;
                cout<< cs - '0'<<endl;
                if(cache[cs - '0']++ < 0) {
                    cout<<"here y++"<<endl;
                    y++;
                }
                cout<< cg - '0'<<endl;
                if(cache[cg - '0']-- > 0) {
                    cout<<"here y--"<<endl;
                    y++;
                }
            }
        }
        string res = to_string(x)+'A'+to_string(y)+'B';
        return res;
    }
};

int main() {
    Solution test;
        int j=0;
        cout<<j;
        if(j++ < 0) cout<<j;
        cout <<j;

    cout<<"\n----------\n";
    string secret = "1807";
    string guess = "7810";
    string ans;
    ans= test.getHint2(secret,guess);
    cout << "guess result "<<ans <<endl;
    return 0;
}