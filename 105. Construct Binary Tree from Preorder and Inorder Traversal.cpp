/**
10:55 - 11:18
use a map to record the index of inorder.
recursively solve sub order array.

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
 private:
     map<int,int>inorderToInroderIndex;

     TreeNode* buildTree(vector<int>& preorder, int preS, int preT,
         vector<int>& inorder, int inS, int inT) {
         if(preS>=preT)return nullptr;
         int curVal = preorder[preS];
         TreeNode* cur = new TreeNode(curVal);
         int leftSize = inorderToInroderIndex[curVal]-inS;
         cur->left=buildTree(preorder,preS+1,preS+1+leftSize,
           inorder,inS,inS+leftSize);
         cur->right=buildTree(preorder,preS+1+leftSize,preT,
           inorder,inS+1+leftSize,inT);
         return cur;
     }
 public:
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         for (int i=0;i<inorder.size();i++) {
             inorderToInroderIndex[inorder[i]]=i;
         }
         return buildTree(preorder,0,preorder.size(),
           inorder,0,inorder.size());
     }
 };