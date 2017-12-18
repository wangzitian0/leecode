/*
给两个有序链表，将它们归并排序

感觉和上个题目差不多，也是拿个二级指针去操作上一级指针的值就好。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans =NULL;
        ListNode **last = &ans;
        while(l1&&l2) {
            if(l1->val < l2->val)
                *last = l1, last = &(l1->next), l1 = l1 -> next;
            else
                *last = l2, last = &(l2->next), l2 = l2 -> next;
        }
        if(l1)*last = l1;
        if(l2)*last = l2;
        return ans;
    }
};