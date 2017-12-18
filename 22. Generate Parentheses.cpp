/*
复杂度是卡特兰数

不知道有么有特殊的展开方式，随手写了个 dfs 水过去了。
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