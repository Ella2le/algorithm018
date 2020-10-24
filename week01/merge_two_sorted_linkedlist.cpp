//
// Created by lewang on 10/23/20.
//

//my violent solution

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* res;
        while(l1 != nullptr || l2!= nullptr){
            ListNode* l1Temp = l1;
            ListNode* l2Temp = l2;

            if(l1Temp >= l2Temp ){
                res=l1;
                ListNode* temp1;
                if(l1Temp->next != nullptr) {
                    temp1 = l1Temp->next;
                    l1Temp = temp1;
                }
            }else {
                res=l2Temp;
                ListNode* temp2;
                if(l1Temp->next != nullptr) {
                    temp2 = l2Temp->next;
                    l1Temp = temp2;
                }
            }

        }
        return res;
    }
//};
//7:31 PM	info
//Compile Error:
//Time Limit Exceeded
//        Your input:[1,2,4]
//[1,3,4]
//stdout:
//

//官方暴力解法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2 ){
        ListNode dummy = ListNode(-1);
        ListNode* prev = &dummy;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2 ->val){
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 == nullptr ?l2:l1;

        return dummy.next;
    }
};
//time O(n+m)
//sapce O1)
//7:50 PM	info
//Success:
//Runtime:8 ms, faster than 86.89% of C++ online submissions.
//Memory Usage:14.7 MB, less than 6.91% of C++ online submissions.


//学习条件运算符的写法 Exp1? Expe2 :Expe3
//prev->next = l1 == nullptr ?l2:l1;
//    等价于
//        if (l1 == nullptr) {
//            prev->next = l2;
//        }else prev->next = l1;
//
//        return dummy.next;
//    8:02 PM	info
//    Success:
//            Runtime:12 ms, faster than 57.31% of C++ online submissions.
//    Memory Usage:14.7 MB, less than 8.93% of C++ online submissions
//    8:03 PM	info
//    Success:
//            Runtime:8 ms, faster than 86.89% of C++ online submissions.
//    Memory Usage:14.7 MB, less than 8.16% of C++ online submissions.

//递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2 ){
        if (l1 == nullptr){
            return l2;
        }else if (l2 == nullptr){
            return l1;
        }else if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
//time O(n+m)
//space O(n+m)