/**
4 min.
just a dfs.

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
    int sum = 0;
    void sumNumbers(TreeNode* cur, int preNum) {
        int curNum = preNum*10 + cur->val;
        if(cur->left==nullptr && cur->right==nullptr) {
            sum += curNum;
            return;
        }
        if(cur->left!=nullptr) {
            sumNumbers(cur->left, curNum);
        }
        if(cur->right!=nullptr) {
            sumNumbers(cur->right, curNum);
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)return 0;
        sumNumbers(root, 0);
        return sum;
    }
};