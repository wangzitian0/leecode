/**
11:57 - 12:02
Very similar with 108, split the ListNodes, then
recursively resolve it.

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
    int getDepth(TreeNode* root, bool &isBalanced) {
        if (!root)return 0;
        int lDep = getDepth(root->left, isBalanced);
        int rDep = getDepth(root->right, isBalanced);
        if(abs(lDep-rDep)>1)isBalanced = false;
        return max(lDep,rDep) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        getDepth(root, isBalanced);
        return isBalanced;
    }
};