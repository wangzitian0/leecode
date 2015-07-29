
#include<bits/stdc++.h>
using namespace std;/**
 * Definition for singly-linked list.
 */ struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s=0;
        ListNode* p=head;
        for(s=0;p;s++)
            p=p->next;
        n=s-n;p=head;
        if(n==0)return head=head->next;
        for(int i=1;p&&i<n;i++)
            p=p->next;
        if(p&&p->next)p->next=p->next->next;
        return head;
    }
};
int main()
{
    Solution x= Solution();
    return 0;
}
