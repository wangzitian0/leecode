/*
给一个单向链表，将第 2k个元素和第2k+1个元素进行交换，如果是奇数，最后一个元素不处理。

还是二级指针操作一下last 和 next。
wa1 next 和 p 指针交换之后位置互换了，不能写类似 p->next->next 的东西。
wa2 last没有给一个新的值，这种错误非常低级，之后要注意。
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
    ListNode* swapPairs(ListNode* head) {
        ListNode **last = &head;
        ListNode *p=head;
        while(p&&p->next) {
            ListNode *nxt = p->next;
            p->next = nxt->next;
            nxt->next = p;
            *last = nxt;
            last = &(p->next);
            p=p->next;
        }
        return head;
    }
};