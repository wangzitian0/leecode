/**
1 min
used a log(n) dfs.
in fact this problem was my favorite interview problem, which has a solution h=log(n), O(h^2)
check -> O(h)
binary search -> O(j)
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
    int count = 0;
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        count++;
        dfs(root->left);
        dfs(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        dfs(root);
        return count;
    }
};