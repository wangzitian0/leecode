/**
10:25-10:32
just a bfs.
Copy code from 102, reverse the queue, remember to swap left and right if reversed.

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
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
         if(root==nullptr)return ans;
         deque<TreeNode*>curLevel,nextLevel;
         curLevel.push_back(root);
         bool reversed = false;
         while(!curLevel.empty()) {
             vector<int>curNodes;
             deque<TreeNode*>nextLevel;
             while(!curLevel.empty()) {
                 TreeNode* cur = curLevel.front();
                 curLevel.pop_front();
                 curNodes.push_back(cur->val);
                 if(!reversed&&cur->left)nextLevel.push_back(cur->left);
                 if(cur->right)nextLevel.push_back(cur->right);
                 if(reversed&&cur->left)nextLevel.push_back(cur->left);
             }
             ans.push_back(curNodes);
             reverse(nextLevel.begin(),nextLevel.end());
             reversed = !reversed;
             curLevel = nextLevel;
         }
         return ans;
     }
 };