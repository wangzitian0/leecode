/*
10:19 - 10:49
index used lots of time.
Just return reverseFirstN(
                 reverseFirstN(
                     reverseFirstN(head, right),
                     right-left+1),
                 right);

*/

/**
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
    ListNode* reverseFirstN(ListNode* head, int n) {
        ListNode *newHead=head;
        ListNode *newTail=nullptr;
        ListNode *curNode=head;
        while(n>0&&curNode) {
            ListNode* nextNode = curNode->next;
            curNode->next = newHead;
            newHead = curNode;
            if(!newTail)newTail=curNode;
            curNode=nextNode;
            n--;
        }
        if(newTail)newTail->next=curNode;
        return newHead;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return reverseFirstN(
            reverseFirstN(
                reverseFirstN(head, right),
                right-left+1),
            right);
    }
};