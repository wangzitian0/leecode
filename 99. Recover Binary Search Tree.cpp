/*
near 1 hours to understand the morris algo
write code 40min.
        // no idea about O(1) space. Searched and fount Morris.
        // for this problem, inorder visit could make the tree to sorted array, then:
        // 1 3 2 4  -> one drop 3->2, find swap i,i+1->(2,3)
        // 1 5 3 4 2 6  -> two drop 5->3 and 4->2, find swap i,j->(5,2)
        // 2 1 4 3 6 5 ->three or more dorp, no ans.
        // find all slot of inorder preNode->val > cur->val
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
public:
    void recoverTree(TreeNode* root) {


        TreeNode* cur=root;
        vector<TreeNode*> drops;
        TreeNode* lastPtr = nullptr;
        while(cur) {
            TreeNode* prv=cur->left;
            if(!prv) {
                // visit cur now.
                if (lastPtr&&lastPtr->val > cur->val) {
                    drops.push_back(lastPtr);
                    drops.push_back(cur);
                }
                lastPtr = cur;
                cur = cur->right;
                continue;
            }
            while(prv->right&&prv->right!=cur) {
                prv = prv->right;
            }
            if(prv->right==cur) {
                prv->right = nullptr;
                // visit cur now.
                if (lastPtr&&lastPtr->val > cur->val) {
                    drops.push_back(lastPtr);
                    drops.push_back(cur);
                }
                lastPtr = cur;
                cur = cur->right;
            } else {
                prv->right = cur;
                cur = cur->left;
            }
        }
        if (drops.size()==2)
            swap(drops[0]->val, drops[1]->val);
        else if (drops.size()==4)
            swap(drops[0]->val, drops[3]->val);
        else cout<<"gg"<<endl;
    }
};