/**
11:28 - 11:32
Copy code from 102,
call levelOrder and reverse the outer side of ans.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        queue<TreeNode*>curLevel,nextLevel;
        curLevel.push(root);
        while(!curLevel.empty()) {
            vector<int>curNodes;
            queue<TreeNode*>nextLevel;
            while(!curLevel.empty()) {
                TreeNode* cur = curLevel.front();
                curLevel.pop();
                curNodes.push_back(cur->val);
                if(cur->left)nextLevel.push(cur->left);
                if(cur->right)nextLevel.push(cur->right);
            }
            ans.push_back(curNodes);
            curLevel = nextLevel;
        }
        return ans;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans=levelOrder(root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};