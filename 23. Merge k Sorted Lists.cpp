/*
K 路归并排序，拿一个堆维护一下最小值即可。

复杂度 O(n*log K)，n 为总元素个数，K 为路数
WA了一下，我假定每个链表都有值，但是实际不一定。
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans=NULL;
        ListNode **last = &ans;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*> >, greater<pair<int,ListNode*> > >hp;
        int n = lists.size();
        for(int i=0;i<n;i++)
            if(lists[i]) {
                hp.push(make_pair(lists[i]->val, lists[i]));
            }
        while(!hp.empty()) {
            pair<int,ListNode*> tp=hp.top();
            hp.pop();
            *last = tp.second;
            last = &(tp.second->next);
            if(tp.second->next)
                hp.push(make_pair(tp.second->next->val, tp.second->next));
        }
        return ans;
    }
};