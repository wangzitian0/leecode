/*
12:27 - 12:47
just dfs, the tree.

WA due to > vs >=, as the problem is that strict greater or less than.

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
    bool isValidBST(TreeNode* root, map<TreeNode*,pair<int,int>>&minMax) {
        if(!root)return true;
        bool ans=true;
        minMax[root] = make_pair(root->val,root->val);
        if(root->left) {
            if (!isValidBST(root->left,minMax)) {
                ans = false;
            } else if (minMax[root->left].second>=root->val) {
                ans = false;
            } else {
                minMax[root].first = min(minMax[root].first,
                  minMax[root->left].first);
            }
        }
        if(root->right) {
            if (!isValidBST(root->right,minMax)) {
                ans = false;
            } else if (root->val>=minMax[root->right].first) {
                ans = false;
            } else  {
                minMax[root].second = max(minMax[root].second,
                  minMax[root->right].second);
            }
        }
        return ans;
    }
public:
    bool isValidBST(TreeNode* root) {
        map<TreeNode*,pair<int,int>>minMax;
        return isValidBST(root,minMax);
    }
};