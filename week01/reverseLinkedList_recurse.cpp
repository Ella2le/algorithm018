//
// Created by lewang on 10/22/20.
//
//反转一个单链表。
//
// 示例:
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
//
// 进阶:
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

//递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr; //要注意heda最后必须手动指向空指针,不然链表中可能会产生循环,如果使用的链表的大小是2的话,就会捕捉到此错误
        return res;
    }
};
//10:06 PM	info
//Success:
//Runtime:8 ms, faster than 95.52% of C++ online submissions.
//Memory Usage:8.6 MB, less than 6.97% of C++ online submissions.


//迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr-> next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};
//10:09 PM	info
//Success:
//Runtime:8 ms, faster than 95.52% of C++ online submissions.
//Memory Usage:8.5 MB, less than 12.74% of C++ online submissions.

