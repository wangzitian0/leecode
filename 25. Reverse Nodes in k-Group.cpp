/*
给一个单向链表，将第[0,k), [k,2k), [2k,3k)区间内的元素倒转，如果剩余的元素不足则不处理。

还是二级指针指来指去，总的来说先想清楚如果反转一个链表，然后再想如何反转 K 个元素，最好想如何把 K 个元素的头尾记录并操作。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p=head;
        int n=0;
        while(p) {
            n++;
            p=p->next;
        }
        p=head;
        ListNode **khead = &head, *last = head;
        for(int z=0;z<n/k;z++) {
            ListNode *p_init = p;
            for(int j=0;j<k;j++) {
                ListNode *nxt = p->next;
                p->next = last;
                last = p;
                p=nxt;
            }
            p_init->next = p;
            *khead = last;
            khead = &(p_init->next);
        }
        return head;
    }
};