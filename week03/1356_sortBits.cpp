//
// Created by lewang on 11/6/20.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        unordered_map<double,int> m;
        vector<double> flag;
        for(int i = 0; i < arr.size(); i++) {
            bitset<16> a(arr[i]);
            long double k;

            if(arr[i] == 0){
                k = 0.;
            }else if(arr[i] == 1){
                k = 0.000001;
            }else{
                k = a.count() - 1./arr[i];
                cout.precision(6);
                cout<<k<<endl;
            }


            flag.push_back(k);
            m[k] = arr[i];
        }
        sort(flag.begin(),flag.end());
        vector<int> res;
        for(int j = 0; j < flag.size(); j++) {
            res.push_back(m[flag[j]]);
            cout.precision(6);
            cout<<flag[j]<<",";
            //cout<<m[flag[j]]<<",";
        }
        cout<<"]"<<endl;
        return res;
    }
};

int main(){
// vector<int> nums {1111,7644,1107,6978,8742,1,7403,7694,9193,4401,377,8641,5311,624,3554,6631};
// Solution test;
// vector<int> res;
// res = test.sortByBits(nums);
// for(auto i : res) cout<<i<<", ";
// cout<<endl;
    cout<<"here2!!"<<endl;
    vector<int> ans;
    cout<<"here1!!"<<endl;
    int k = 5;
    int res;
    ans.push_back(1);
    int id1 = 0, id2 = 0, id3 = 0;
    cout<<"here!!"<<endl;
    for(int i = 1; i < k; i++){
        ans.push_back(min(min(ans[id1]*3,ans[id2]*5),ans[id3]*7));
        cout<<ans.back()<<endl;
        if(ans[i] == ans[id1]*3) id1++;
        if(ans[i] == ans[id2]*5) id2++;
        if(ans[i] == ans[id3]*7) id3++;
    }
    res = ans.back();
    cout<<res;
  //  return res;
 return 0;
}