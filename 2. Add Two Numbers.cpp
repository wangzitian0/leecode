/*
给两个表示一个大数的非空列表，包含倒序的数字，每个节点包含一个数字。求两个大数相加的结果。

就是个简单的链表处理，直接扫一遍求答案即可。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = NULL, *last = NULL;
        int p = 0;
        while(l1 || l2 || p) {
            if (l1) {
                p += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                p += l2->val;
                l2 = l2->next;
            }
            ListNode *tmp = new ListNode(p%10);
            if(!last) {
                ans = tmp;
                last = ans;
            } else {
                last->next = tmp;
                last = last->next;
            }
            p /= 10;
        }
        return ans;
    }
};