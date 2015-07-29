
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans=NULL,*last=NULL;
        while(l1||l2)
        {
            if(l1&&(l2==NULL||l1->val<l2->val))
            {
                if(last==NULL)ans=l1;
                else last->next=l1;
                last=l1;
                l1=l1->next;
            }
            else
            {
                if(last==NULL)ans=l2;
                else last->next=l2;
                last=l2;
                l2=l2->next;
            }
            last->next=NULL;
        }
        return ans;
    }
};

int main()
{
    Solution x= Solution();
}
