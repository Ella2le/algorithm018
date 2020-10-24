//
// Created by lewang on 10/22/20.
//
//递归
class Solution{
public:
    ListNode* swapPair(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPair(newHead->next);
        newHead->next =head;
        return newHead;
    }
};
//9:59 PM	info
//Success:
//Runtime:0 ms, faster than 100.00% of C++ online submissions.
//Memory Usage:7.6 MB, less than 19.47% of C++ online submissions.


//迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        while(temp->next != nullptr && temp->next->next != nullptr){
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummyHead->next;
    }
};
//9:55 PM	info
//Success:
//Runtime:4 ms, faster than 67.60% of C++ online submissions.
//Memory Usage:7.8 MB, less than 5.20% of C++ online submissions.

class Solution {
public:
    ListNode* swapPair(ListNode* head) {
        ListNode* temp = head;
        while(temp->next != nullptr && temp->next-next != nullptr){
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return head;//这里return  head 不对

    }
};
//9:54 PM	info
//Wrong Answer:
//input:[1,2,3,4]
//Output:[1,3,2,4]
//Expected:[2,1,4,3]
//stdout:
