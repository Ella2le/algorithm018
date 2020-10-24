//
// Created by lewang on 10/24/20.
//

//按行来求
//但是在[2,0,2]测试的时候出错了
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int sum = 0;
//        int max = getMax(height);
//        for (int i = 0; i < max ; ++i) {
//            bool isStart = false;
//            int temp_sum = 0;
//            for (int j = 0; j < height.size();j++) {
//                if (isStart && height[j] < i) {
//                    temp_sum++;
//                }
//                if (height[j] >= i) {
//                    sum = sum + temp_sum;
//                    temp_sum = 0;
//                    isStart = true;
//                }
//            }
//        }
//        return sum;
//    }
//
//private:
//    int getMax(vector<int>& height) {
//        int max = 0;
//        for (int i = 0; i < height.size(); ++i) {
//            if (height[i] > max) {
//                max = height[i];
//            }
//        }
//        return max;
//    }
//};

//暴力法,和上面的差不多,时间复杂度都是O(n^2)
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int ans = 0;
//        int size = height.size();
//        for (int i =1; i < size -1; i++) {
//            int max_left = 0, max_right = 0;
//            for (int j= i ; j >= 0; j--) {
//                max_left = max(max_left,height[j]);
//            }
//            for (int j = i; j < size; j++) {
//                max_right = max(max_right, height[j]);
//            }
//            ans += min(max_left, max_right) - height[i];
//        }
//        return ans;
//    }
//};
//8:00 PM	info
//Compile Error:
//Time Limit Exceeded

//动态编程
//时间复杂度O(n)
//空间复杂度O(n)
//Success:
//Runtime:32 ms, faster than 5.79% of C++ online submissions.
//Memory Usage:14.3 MB, less than 5.02% of C++ online submissions.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int ans = 0;

        int size = height.size();
        cout<<"size: " <<size<<endl;
        if(size == 0) return 0;
        vector<int> leaf_max(size), right_max(size);
        leaf_max[0] = height[0];
        for (int i = 1; i < size; ++i) {
            leaf_max[i] = max(height[i], leaf_max[i-1]);
            cout << leaf_max[i] << ",";
        }
        cout << endl;

        right_max[size - 1] = height[size - 1];
        for(int i = size -2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i+1]);
            cout << right_max[i] << ",";
        }
        cout << endl;
        for (int i = 1; i < size-1; i++) {
            ans += min(leaf_max[i], right_max[i]) - height[i];
            cout<< ans << ",";
        }
        cout<<endl;
        return ans;
    }
    //栈的应用
    //时间复杂度O(n)
    //空间复杂度O(n)
    //8:53 PM	info
    //Success:
    //Runtime:16 ms, faster than 9.46% of C++ online submissions.
    //Memory Usage:14.5 MB, less than 5.02% of C++ online submissions.
    //
    int trap2(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top =st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
    //使用双指针
    //时间复杂度O(n)
    //空间复杂度O(1)
//
//    Success:
//    Runtime:8 ms, faster than 57.56% of C++ online submissions.
//    Memory Usage:14.3 MB, less than 5.02% of C++ online submissions.
    int trap3(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if(height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};





int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution test;
    int water = test.trap3(height);
    cout << water <<endl;
    return 0;
}