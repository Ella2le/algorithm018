//
// Created by lewang on 10/20/20.
//
//思路:
//数组末尾加1,然后输出!! 没有考虑清楚各种情况！！！
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public: vector <int> plusOne(vector<int>& digits){
        int len = digits.size();
        for(int i = len - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if(digits[i]!=0)
                return digits;
        }

        digits.insert(digits.begin(),1);

        return digits;
    }
};




/*Java solution
class Solution {
public int[] plusOne(int[] digits) {
        int len = digits.length;
        for(int i = len - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if(digits[i]!=0)
                return digits;
        }
        digits = new int[len + 1];
        digits[0] = 1;
        return digits;
    }
}

        作者：guanpengchn
        链接：https://leetcode-cn.com/problems/plus-one/solution/hua-jie-suan-fa-66-jia-yi-by-guanpengchn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/





//---------------------------------我的错误解法-----------------------------------------------------------
//class Solution {
//public:
//    vector <int> plusOne(vector<int>& digits){
//        vector<int>::iterator it;
//        int lastNum = digits.back();
//        lastNum += 1;
//        digits.pop_back();
//        digits.push_back(lastNum);
//        int size = digits.size();
//        for (int i=size+1; i>0 ; i-- ){
//            cout << digits[i] << ",";
//        }
////        it = digits.end();
////        cout << digits.back() <<endl;
////        int size = digits.size();
////        int base = 10;
////        int output = 0;
////        for (int i = size; i >=0; i--){
////
////            output = output*base+ digits[i];
////        }
//    }
//};
//
//int main(){
//    Solution test;
//    vector<int> a ;
//    a.push_back(1);
//    a.push_back(2);
//    a.push_back(3);
//    test.plusOne(a);
//    cout << "[MSG] Finish" << endl;
//return 0;
//}
