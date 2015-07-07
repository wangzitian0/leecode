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
        ListNode* ans=NULL;
        ListNode* last=NULL;
        int delta=0;
        while(true)
        {
            if(l1)
                delta+=l1->val,l1=l1->next;
            if(l2)
                delta+=l2->val,l2=l2->next;
            if(delta||l1||l2)
            {
                ListNode* p=new ListNode(delta%10);
                if(ans==NULL)ans=p;
                if(last) last->next=p;
                last=p;
                delta/=10;
            }
            else break;
        }
        if(ans==NULL)ans = new ListNode(0);
        return ans;
    }
};
