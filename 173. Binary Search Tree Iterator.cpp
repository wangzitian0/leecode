/**
near 30min.
use a stack to mock the dfs.
vector<pair<TreeNode*, int>> stackH;  // <ptr, status>
status auto increase as the program run to next line.
0. init(context) // get current stack[cur]
1. dfs(l)        // push to stack[cur+1]
2. output(val)   // do something in stack[cur]
3. dfs(r)        // push to stack[cur+1]
4. quit(resp)    // pop the stack top, put the resp to stack[cur-1]
let status = next line you will run.

 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
private:
    vector<pair<TreeNode*, int>> stackH; // <ptr, status>
    bool hasRunNext = false;
    int nextVal = 0;
public:
    BSTIterator(TreeNode* root) { stackH.push_back(make_pair(root, 0)); }

    int next() {
        if (!hasRunNext) {
            hasNext();
        }
        hasRunNext = false;
        return nextVal;
    }

    bool hasNext() {
        while (stackH.size() > 0) {
            TreeNode* cur = stackH.back().first;
            ++stackH.back().second;
            if (stackH.back().second == 1) {
                if (cur->left != nullptr) {
                    stackH.push_back(make_pair(cur->left, 0));
                }
            } else if (stackH.back().second == 2) {
                // cout << stackH.back().first->val<<endl;
                hasRunNext = true;
                nextVal = stackH.back().first->val;
                return true;
            } else if (stackH.back().second == 3) {
                if (cur->right != nullptr) {
                    stackH.push_back(make_pair(cur->right, 0));
                }
            } else {
                stackH.pop_back();
            }
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */