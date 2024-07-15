/*

9:35 - 9:50

Just linked list ops
Forgot so many cases.
RE1
        tail1->next = head2;
        tail2->next = nullptr;
        return head1;
WA2
        if(tail1)tail1->next = head2;
        if(tail2)tail2->next = nullptr;
        return head1;
AC

        if(tail1)tail1->next = head2;
        if(tail2)tail2->next = nullptr;
        if (!head1)return head2;
        return head1;

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1=nullptr;
        ListNode* head2=nullptr;
        ListNode* tail1=nullptr;
        ListNode* tail2=nullptr;
        while(head) {
            if (head->val < x) {
                if(!tail1)
                    head1 = tail1 = head;
                else {
                    tail1->next = head;
                    tail1 = tail1->next;
                }
            } else {
                if(!tail2)
                    head2 = tail2 = head;
                else {
                    tail2->next = head;
                    tail2 = tail2->next;
                }
            }
            head = head ->next;
        }
        if(tail1)tail1->next = head2;
        if(tail2)tail2->next = nullptr;
        if (!head1)return head2;
        return head1;
    }
};