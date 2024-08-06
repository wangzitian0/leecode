/**
11:11 - 11:42.
something like dp
for a case node cur, if the ans appear at cur, there are 4 cases:
- father-cur
- father-cur-left
- father-cur-right
- left-cur-right

then, dfs the tree, return the max(cur)
ans = max(cur_val + max{0, f[l], f[r], f[l]+f[r]})
f[cur]=max{0, f[l], f[r]}+cur_val | which means the max path sum without father-cur.
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
    static constexpr int oo = 1e9;
    unordered_map<TreeNode*, int>dp;
    int ans = -oo;
    int dfs(TreeNode* cur) {
        if (cur == nullptr) {
            return 0;
        }
        int curAns = cur->val;
        int curMax = 0;
        if (cur->left!=nullptr) {
            int fl = dfs(cur->left);
            curMax = max(curMax, fl);
            curAns += fl;
        }

        if (cur->right!=nullptr) {
            int fr = dfs(cur->right);
            curMax = max(curMax, fr);
            curAns += fr;
        }
        ans = max(ans, curAns);
        ans = max(ans, curMax + cur->val);
        return curMax + cur->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};