//
// Created by lewang on 10/27/20.
//
//剑指offer 59 -i 滑动窗口的最大值

//使用双端队列求解
//设定双端队列deque实现费严格递减的单调队列,对手就是当前滑动窗口内的最大元素
//step1-当出 滑动窗口的元素恰好就是单调队列的队头元素,一起出栈
//step2-让所有小于新加入元素的单调队列元素出队,新元素,入队
//step3-形成滑动窗口后,取队首元素加入结果

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < k || k <= 0) return {};//特殊情况

        int left = 1 - k; //左边界范围[1-k,n+1-k]??? [0,n-1-k]为什么不是这个呢??
        int right = 0; //右边界范围[0,n-1]???? [k,n-1]

        deque<int> dq; //双端队列
        vector<int> res;

        while (right < len) {
            //判断deque的左边界是不是最大的元素
            if(left >= 1 && nums[left -1] == dq[0]){
                dq.pop_front();
            }
//            while (!dp.empty() && dp[0] < nums[right]) {
//                dp.pop_front();//小于nums[right]的元素出队
//            }
            while (!dq.empty() && dq[dq.size()-1] < nums[right] ){
                dq.pop_back(); //小于nums[left]的元素出队
            }
            cout << nums[right] << endl;
            dq.push_back(nums[right]);

            if(left >= 0){
                res.push_back(dq[0]);
                cout<< dq[0] << endl;
            }
            left++;
            right++;
        }
        return res;

    }
    //
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        vector<int> re;
        deque<int> dq;
        size_t n= nums.size();
        for(int i = 0; i < n; i++) {
            //while为了维护单调队列的对头是当前最大的元素的序号
            while (!dq.empty() && nums[dq.front()] < nums[i]) {
                dq.pop_front();
            }//如果当前的单调队列的头小于nums[i],则弹出

            dq.push_front(i);//把当前的元素的序号插入队头
            cout<< i - dq.back()<<endl;
            if (i - dq.back() >= k)
            {
                cout<<dq.back();
                dq.pop_back();//如果当前的deque的长度超过k,删除已经挪出滑动窗口的数
                // 即Deque有超过3个以上的数,说明最大的这个数已经移除了当前的3的长度的窗口,即使他最大也需要删除他
            }

            if(i >= k -1){
                re.push_back(nums[dq.back()]);//队列的长度达到k,输出当前队列的队尾元素(即最大值)到return的数组中
            }

        }
        return re;

    }

    //参考国际网站


};

int main(){
    Solution test;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res;
    res = test.maxSlidingWindow2(nums,k);
    for (auto i : res) cout<< i <<"," ;
    return 0;
}