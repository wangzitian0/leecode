/**
12:02 - 12:10
just dfs to get the min.

WA for edge case: root = nullptr.
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
     int minDepth(TreeNode* root) { // correct
         if (!root) return 0;
         if (!root->left && !root->right) return 1;
         int ans = 0x7FFFFFFF;
         if (root->left)ans = min(ans, minDepth(root->left));
         if (root->right)ans = min(ans, minDepth(root->right));
         return ans + 1;
     }
     int minDepth(TreeNode* root) { // wrong if root = null, it required 0.
         if (!root) return 0x7FFFFFFF;
         if (!root->left && !root->right) return 1;
         return min(minDepth(root->left), minDepth(root->right)) + 1;
     }
 };