
#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode **last =&head,*ll=NULL,*p=NULL,*nxt=NULL,*nxt2=NULL;
		while(*last)
		{
			ll=*last;
			p=ll;
			int j;
			for(j=0;j<k&&p;j++)
				p=p->next;
			if(j==k&&k>1)
			{
				p=ll;
				nxt=p->next;
				nxt2=nxt->next;

				for(int i=0;i<k-1&&p;i++)
				{
					nxt->next=p;
					p=nxt;
					nxt=nxt2;
					if(nxt2)nxt2=nxt2->next;else nxt2=NULL;
				}

				*last=p;
				last=&(ll->next);
				(*last)=nxt;
			}
			else break;
		}
		return head;
    }
};
int main()
{
    Solution x= Solution();
    ListNode a(1),b(2),c(3),d(4),*hd,*p;
    hd=&a;
    a.next=&b;
    b.next=&c;
    c.next=&d;
    p=hd;
    while(p)
        printf("%d\n",p->val),p=p->next;
    p=x.reverseKGroup(hd,1);
    while(p)
        printf("%d\n",p->val),p=p->next;
}
