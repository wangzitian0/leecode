
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **last=&head,*tl,*tr;
        while(*last&&(*last)->next)
        {
            tl=*last;tr=tl->next;
            tl->next=tr->next;
            tr->next=tl;
            *last=tr;
            last=&(tl->next);
        }
        return head;
    }
};
int main()
{
    Solution x= Solution();
}
