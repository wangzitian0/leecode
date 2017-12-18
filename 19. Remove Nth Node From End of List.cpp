/*
给一个链表，删掉倒数第 n 个。

拿个二级指针去操作下指向自己的节点的 next 就好了。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode **last = &head, *p = head;
        while(p) {
            cnt++;
            p=p->next;
        }
        int z=0;
        p=head;
        while(z<cnt-n) {
            z++;
            last = &(p->next);
            p=p->next;
        }
        *last = p->next;
        return head;
    }
};