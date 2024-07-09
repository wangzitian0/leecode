/*
8:10-8:45
blocked for long time....
void rotate(ListNode* head) {
        if(!head)return;
        ListNode *p = head, *prev_node = nullptr;
        while(p->next) {
            prev_node = p;
            cout<< p->val;
            p=p->next;
        }
        if (prev_node) { // if size == 1, prev = nullptr
            // 4   5   1   2   3
            // head       pre  p
            p->next = head;
            head = p; // !!!!!!!this p did not change out side head's value. sh*t!!!
            prev_node->next = nullptr;
            cout<< endl<<head->val << " "<< head->next->val<<endl;
        }
    }




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
  private:
      int n;
      int getLen(ListNode* head) {
          int len=0;
          ListNode* p=head;
          while(p){
              len++;
              p=p->next;
          }
          return len;
      }
      ListNode* rotate(ListNode* head) {
          if(!head)return head;
          ListNode *p = head, *prev_node = nullptr;
          while(p->next) {
              prev_node = p;
              cout<< p->val;
              p=p->next;
          }
          if (prev_node) { // if size == 1, prev = nullptr
              // 4   5   1   2   3
              // head       pre  p
              p->next = head;
              head = p;
              prev_node->next = nullptr;
              cout<< endl<<head->val << " "<< head->next->val<<endl;
          }
          return head;
      }
  public:
      ListNode* rotateRight(ListNode* head, int k) {
          n = getLen(head);
          if(n)k = k%n;
          for(int i=0;i<k;i++)
              head = rotate(head);
          return head;
      }
  };