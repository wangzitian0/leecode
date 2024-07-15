/*

linked list iterator.
spent 30min.
two point index used lots of time.

*//**
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
      ListNode* deleteDuplicates(ListNode* head) {
          ListNode toHead = ListNode(0, head);
          ListNode* lastNumPtr = &toHead;
          ListNode* p = head;
          int cnt = 0;
          while(p) {
              if(p->next&&lastNumPtr->next->val == p->next->val) {
                  cnt++;
              } else {
                  if(cnt == 0) {
                      lastNumPtr = p;
                  } else {
                      lastNumPtr->next = p->next;
                  }
                  cnt = 0;
              }
              p = p->next;
          }
          return toHead.next;
      }
  };