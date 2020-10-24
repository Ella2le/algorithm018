//
// Created by lewang on 10/23/20.
//

//1.暴力解法
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        if(k == 0 || nums.size() ==  0) return ;
//        int kk= k % (nums.size());
//        vector<int> temp(nums.end() - kk, nums.end());
//        nums.erase(nums.end()-kk,nums.end());
//        for(int j=temp.size()-1; j >= 0;j--){
//            nums.emplace(nums.begin(),temp[j]);
//        }
//
//    }
//};
////};
//1:44 PM	info
//Success:
//Runtime:264 ms, faster than 5.43% of C++ online submissions.
//Memory Usage:10.1 MB, less than 5.16% of C++ online submissions.
//2.三次反转
//class Solution {
//public:
////    template <class BidirectionIteration>
////    void reverse (BidirectionIteration first, BidirectionIteration last){
////        while ((first != last )&& (first != --last)){
////            std::iter_swap(first,last);
////            ++first;
////        }
////    }
//    void rotate(vector<int>& nums, int k) {
//        if( nums.size() == 0 || k==0) return;
//        reverse(nums.begin(),nums.end());
//        reverse(nums.begin(),nums.begin()+k%nums.size());
//        reverse(nums.begin()+k%nums.size(),nums.end());
//    }
//};//
//2:08 PM	info
//Success:
//Runtime:8 ms, faster than 86.45% of C++ online submissions.
//Memory Usage:9.8 MB, less than 30.77% of C++ online submissions.
//3.环装替代
//class Solution {
//public:
//
//    void rotate(vector<int>& nums, int k) {
//        int len = nums.size();
//        if(len == 0 || k == 0 || len == k ) return;
//        k = k%len;
//        int count = 0;
//        for (int start = 0 ;count < len; start++){
//            int cur = start;
//            int pre = nums[cur];
//            do{
//                int next = (cur+k) % len;
//                int temp = nums[next];
//                //iter_swap(nums.begin()+cur-1,nums.begin()+next-1);
//                nums[next] = pre;
//                pre = temp;
//                cur =next;
//                count ++;
//            }while(start != cur);
//        }
//    }
//};
//
//2:43 PM	info
//Success:
//Runtime:4 ms, faster than 98.98% of C++ online submissions.
//Memory Usage:10.1 MB, less than 5.16% of C++ online submissions.
#include <iostream>
#include <vector>
using namespace std;
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        int kk= k % (nums.size());
//        if(nums.size() == k || k == 0 || kk == 0)
//        auto it = nums.end();
//
//        vector<int> temp ( nums.end() - kk -1, nums.end());
//        //for (auto&& i:nums) cout<<i<<",";
//        nums.emplace(nums.begin(),temp);
//        nums.erase(nums.end()-kk,nums.end());
//        //return nums;
//    }
//};
template <class BidirectionIteration>
        void reverse (BidirectionIteration first, BidirectionIteration last){
            while ((first != last )&& (first != --last)){
                std::iter_swap(first,last);
                ++first;
            }
        }

int main(){
    vector<int> nums  {1,2,3,4,5,6,7};
    cout<< "nums: ";
    for(auto i:nums) cout<<i<<",";
    cout << endl;
    int k = 3;




    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k%nums.size());
    reverse(nums.begin()+k%nums.size(),nums.end());
//
//    int kk= k % (nums.size());
//    vector<int> temp ( nums.end() - kk, nums.end());
//
//    cout<< "temp: ";
//    for (auto k:temp) cout<<k<<",";
//    cout<<endl;
//
//
//    nums.erase(nums.end()-kk,nums.end());
//    for(int j=temp.size()-1; j >= 0;j--){
//        nums.emplace(nums.begin(),temp[j]);
//    }
////    for (auto j:temp) nums.emplace(nums.begin(),j);
////    for (auto j:temp) {
////        //int t = temp.back();
////        temp.emplace(temp.end(), j);
////
////    }
////    for (auto k:temp) cout<<k<<",";
////    cout<<endl;
//    //nums.emplace(nums.begin(),5);

    cout<<"After rotation: ";
    for(auto i:nums) cout<<i<<",";
    cout << endl;

    //Solution test;
   // test.rotate(nums,k);
    //for(auto i:nums) cout<<i<<",";
    return 0;
}

