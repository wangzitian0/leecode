/**
08:12 - 09:20
similar like morris, but in fact, not need.
remove the code from morris.
just merge the left side to right side, as:
1. cur right subtree move to the cur left node's most right node's right
2. move left subtree to cur's right.

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
     void flatten(TreeNode* root) {
         TreeNode* cur = root;
         while(cur) {
             if (!cur->left) {
                 cout<<cur->val<<endl;
                 cur = cur->right;
             } else {
                 TreeNode* prev = cur->left;
                 while(prev->right) {
                     prev = prev->right;
                 }
                 cout<<cur->val<<endl;
                 prev->right = cur->right;
                 cur->right = cur->left;
                 cur->left = nullptr;
                 cur = cur->right;
             }
         }
     }
 };