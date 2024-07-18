/**
07:52 - 08:12
just dfs.
when go to the leaf node, record the ans.

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
    void hasPathSum(TreeNode* root, int targetSum,
      vector<int>&cur, vector<vector<int>> &ans) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right && targetSum==root->val) {
            cur.push_back(root->val);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(root->val);
        hasPathSum(root->left, targetSum - root->val, cur, ans);
        hasPathSum(root->right, targetSum - root->val, cur, ans);
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>cur;
        hasPathSum(root, targetSum, cur, ans);
        return ans;
    }
};