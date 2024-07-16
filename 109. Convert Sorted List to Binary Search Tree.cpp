/**
11:42 - 11:57
Very similar with 108, split the ListNodes, then
recursively resolve it.

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)return nullptr;
        ListNode* mid = head;
        ListNode* cur = head;
        ListNode* last = nullptr;
        while(cur&&cur->next&&cur->next->next) {
            last = mid;
            mid = mid ->next;
            cur = cur->next->next;
        }
        ListNode* rightNodes = mid->next;
        if(last)last->next = nullptr;
        else head = nullptr;
        TreeNode* treeNode = new TreeNode(mid->val);
        treeNode->left = sortedListToBST(head);
        treeNode->right = sortedListToBST(rightNodes);
        return treeNode;
    }
};