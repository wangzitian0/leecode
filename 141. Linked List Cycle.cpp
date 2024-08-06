/**
19:48 - 19:57

fast and slow ptr.
if never meet, it was false.
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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode *fast = head, *slow = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            } else {
                return false;
            }
        } while (fast != nullptr && fast != slow);
        return fast == slow;
    }
};