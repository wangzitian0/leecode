/*
11:27 - 11:59
dfs got left tree and right tree ans
current node ans = left tree ans x right tree ans

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
    TreeNode* deepCopy(TreeNode* root) {
        if(!root)return nullptr;
        // here use the unique_ptr
        auto curNode = new TreeNode(root->val);
        curNode->left=deepCopy(root->left);
        curNode->right=deepCopy(root->right);
        return curNode;
    }
    vector<TreeNode*> generateTree(int s, int t) {
        if(s>t)return vector<TreeNode*>(1, nullptr);
        vector<TreeNode*> ans;
        for(int i=s;i<=t;i++) {
            vector<TreeNode*> leftTree = generateTree(s,i-1);
            vector<TreeNode*> rightTree = generateTree(i+1,t);
            cout<<s<<" "<<t<<": "<<i<<" "<<rightTree.size()<<endl;
            for(auto left : leftTree) {
                for(auto right : rightTree) {
                    auto curNode = TreeNode(i,left,right);
                    ans.push_back(deepCopy(&curNode));
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTree(1,n);
    }
};