/**
just compare
WA1: missing the case p==null and q==null
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*,TreeNode*>>que;
        que.push(make_pair(p,q));
        while(!que.empty()){
            auto tmp=que.front();
            que.pop();
            TreeNode* l = tmp.first;
            TreeNode* r = tmp.second;
            if(!l&&!r) {
                continue;
            } else if (!l || !r || l->val!=r->val) {
                return false;
            }
            que.push(make_pair(l->left,r->left));
            que.push(make_pair(l->right,r->right));
        }
        return true;
    }
};