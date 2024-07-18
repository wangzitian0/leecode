/**
11:02 - 11:42
pretty hard without extra space.
Just use the next as a linked list, then like bfs extend another level.

WA1: idea wrong. for this case

       1
   2      3
 4   5       7
8              15


 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node* curLevelHead = root;
        while (curLevelHead) {
            Node* cur = curLevelHead;
            Node* nextLevelHead = nullptr;
            Node* nextLevelTail = nullptr;
            while (cur) {
                // append cur->left
                if (cur->left) {
                    if (nextLevelTail) {
                        nextLevelTail->next = cur->left;
                    } else {
                        nextLevelHead = cur->left;
                    }
                    nextLevelTail = cur->left;
                }

                // append cur->right
                if (cur->right) {
                    if (nextLevelTail) {
                        nextLevelTail->next = cur->right;
                    } else {
                        nextLevelHead = cur->right;
                    }
                    nextLevelTail = cur->right;
                }

                cur = cur->next;
            }


            curLevelHead = nextLevelHead;
        }
        return root;
    }
};