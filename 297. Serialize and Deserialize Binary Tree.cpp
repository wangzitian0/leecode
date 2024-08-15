// 22:25 - 22:58
// just use pre-order to serialize, this is very simple.
// for deserialize, return the length of current tree,
// record the left tree length, then use its index as the begin of right
// WA * 1, negtive numbers.....
// blocked very long time on this place:
// if (s < data.size() && data[s] != '#' && !isDigits(data[s]))
// T_T, I forget that serialize added some extra ' '
//        str += ", " + serialize(root->left);
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    bool isDigits(char ch) { return ch == '-' || (ch >= '0' && ch <= '9'); }
    pair<TreeNode*, int> deserialize(const string& data, int s) {
        while (s < data.size() && data[s] != '#' && !isDigits(data[s])) {
            s++;
        }
        // cout << "s-->" << s << " "<< data[s] << endl;
        if (s == data.size() || data[s] == '#') {
            return make_pair(nullptr, s + 1);
        }
        int val = 0, op = 1;
        while (isDigits(data[s])) {
            if (data[s] == '-') {
                op = -op;
            } else {
                val = val * 10 + data[s] - '0';
            }
            s++;
        }
        // cout << val << " " << s << endl;
        TreeNode* node = new TreeNode(op * val);
        pair<TreeNode*, int> tmp;
        tmp = deserialize(data, s);
        node->left = tmp.first;
        tmp = deserialize(data, tmp.second);
        node->right = tmp.first;
        return make_pair(node, tmp.second);
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "#";
        }
        string str = to_string(root->val);
        str += ", " + serialize(root->left);
        str += ", " + serialize(root->right);
        // cout << str << endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { return deserialize(data, 0).first; }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));