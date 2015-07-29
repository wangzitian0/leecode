
#include<bits/stdc++.h>
using namespace std;
class Solution {
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while(lists.size()>1)
        {
            vector<ListNode*> tmp;
            int n=lists.size();
            for(int i=0;i*2+1<n;i++)
                tmp.push_back(mergeTwoLists(lists[i*2],lists[i*2+1]));
            if(n%2)
                tmp.push_back(lists[n-1]);
            lists.erase(lists.begin(),lists.end());
            for(int i=0;i<tmp.size();i++)
                lists.push_back(tmp[i]);
        }
        if(lists.size()==0)return NULL;
        return lists[0];
    }
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
