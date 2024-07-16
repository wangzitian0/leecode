/**
11:18 - 11:28
basically same with 105.
Just change some indexes.

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

     TreeNode* buildTree(vector<int>& postorder, int postS, int postT,
         vector<int>& inorder, int inS, int inT) {
         if(inS>=inT)return nullptr;
         int curVal = postorder[postT-1];
         TreeNode* cur = new TreeNode(curVal);
         int leftSize = inorderToInroderIndex[curVal]-inS;
         cur->left=buildTree(postorder,postS,postS+leftSize,
           inorder,inS,inS+leftSize);
         cur->right=buildTree(postorder,postS+leftSize,postT-1,
           inorder,inS+1+leftSize,inT);
         return cur;
     }
 public:
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         for (int i=0;i<inorder.size();i++) {
             inorderToInroderIndex[inorder[i]]=i;
         }
         return buildTree(postorder,0,postorder.size(),
           inorder,0,inorder.size());
     }
};