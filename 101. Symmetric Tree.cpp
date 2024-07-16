/**
10:00-10:15
just used a tree hash.
RE: hashBase and HashMod used 1e12 and 1e6 make sure its produce inside long long.
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
     long long HashMod = 1e12-11;
     long long HashBase = 1e6+3;
     long long treeHash(TreeNode* cur, bool reversed) {
         if(!cur) return 0LL;
         vector<long long>hash;
         hash.push_back(treeHash(cur->left, reversed));
         hash.push_back(cur->val);
         hash.push_back(treeHash(cur->right, reversed));
         if (reversed)reverse(hash.begin(),hash.end());
         long long ans = 0;
         for(auto hs : hash)
             ans = (ans*HashBase + hs + HashBase/2)%HashMod;
         cout<<cur->val<<" "<<ans<<endl;
         return ans;
     }
 public:
     bool isSymmetric(TreeNode* root) {
         if(!root)return true;
         return treeHash(root->left,false)==treeHash(root->right, true);
     }
 };