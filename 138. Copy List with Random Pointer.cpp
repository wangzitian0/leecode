/**
19:05 - 19:35
draw cases in paper, and find 3 step copy:
- copy the node next to the current nodes. which could make random very 'near' to the original nodes.
- got the fixed random, by lots of next operation.
- split two list.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* cur = head;
        while (cur != nullptr) {
            Node* nextNode = new Node(cur->val);
            nextNode->next = cur->next;
            cur->next = nextNode;
            cur = nextNode->next;
        }
        cur = head;
        while (cur != nullptr) {
            if (cur->random == nullptr) {
                cur->next->random = nullptr;
            } else {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        Node *resp = head->next;

        cur = head; // forgot this and got 'Next pointer of node with label 7 from the original list was modified.'
        while (cur != nullptr) {
            Node *cur2 = cur->next;
            if (cur2->next == nullptr) {
                cur->next = nullptr;
            } else {
                cur->next = cur->next->next;
                cur2->next = cur2->next->next;
            }
            cur = cur->next;
        }
        return resp;
    }
};