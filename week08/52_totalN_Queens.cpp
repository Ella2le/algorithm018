//
// Created by lewang on 12/12/20.
//
#include<iostream>
#include<bitset>

using namespace std;

class Solution {
    int count = 0;
public:
    int totalNQueens(int n) {

        dfs(n, 0,0,0,0);
        return count;
    }

    void dfs(int &n, int row, int cols, int pie, int na){
        cout<<"-------------row:"<<row<<"----------"<<endl;
        if(row >= n) {
            count+=1;
            cout<<"count:"<<count<<endl;
            return;
        }
        //bits上1的位置代表可以放置
        int bits = (~(cols|pie|na)) & ((1<<n) - 1);
        cout<< "where can put in bits: " << bits << "|" << bitset<4>(bits) << endl;
        cout<<"*******************"<<endl;
        while(bits){
            int p = bits & -bits;//得到最低位的1
            cout<< "where to put p: " << p << "|" << bitset<4>(p) << endl;
            bits = bits & (bits-1); //清零最低位的1
            cout<< "After put P bits: " << bits << "|" << bitset<4>(bits) << endl;
            dfs(n,row+1,cols|p, (pie|p)<<1,(na|p)>>1);


        }
    }

};
//col|p = 0000|0001 = 0001;
//(pie|p)<<1 = 0010;
//(na|p) >>1 = 0000;
//~(col|pie|na) = ~(0011)=1100 //第一次放在第一列的最右边后0001，下一次只能放第二列的1100

int main(){
    Solution test;
    int n = 4;
    cout<<(1<<n) - 1<<"|"<< bitset<4>((1<<n) - 1)<<endl;
    //将x最高位到第n位(含)清零:x & ((1 << n) - 1)
    cout<<(1<<n) <<"|"<< bitset<5>((1<<n))<<endl;
    int res = test.totalNQueens(4);
    cout << res << endl;
    return 0;
}
