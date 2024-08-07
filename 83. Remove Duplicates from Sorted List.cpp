/*

linked list iterator.
4 min.

*//**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     ListNode *next;
   *     ListNode() : val(0), next(nullptr) {}
   *     ListNode(int x) : val(x), next(nullptr) {}
   *     ListNode(int x, ListNode *next) : val(x), next(next) {}
   * };
   */class Solution {
     public:
         ListNode* deleteDuplicates(ListNode* head) {
             ListNode *p=head;
             while(p) {
                 if (p->next&&p->next->val==p->val) {
                     // remove p->next;
                     p->next= p->next->next;
                     continue;
                 }
                 p = p->next;
             }
             return head;
         }
     };