/**

spent near 1 hours to handle different pointers.

 */


class LRUCache {
private:
    struct Node {
        int val, key;
        Node* next;
        Node* pre;
    };
    Node* pt; // next is the head, pre is the tail;
    unordered_map<int, Node*> keyToNode;
    int cap;
    void insertToHead(Node* cur) {
        Node* head = pt->next;
        head->pre = cur;
        cur->next = head;
        cur->pre = pt;
        pt->next = cur;
    }
    void moveOut(Node* cur) {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
    }
    Node* moveToHead(int key) {
        if (keyToNode.find(key) != keyToNode.end()) {
            Node *cur = keyToNode[key];
            moveOut(cur);
            insertToHead(cur);
            return cur;
        }
        return nullptr;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        pt = new Node();
        pt->next = pt;
        pt->pre = pt;
    }

    int get(int key) {
        Node* cur = moveToHead(key);
        if (cur != nullptr) {
            return cur->val;
        }
        return -1;
    }

    void put(int key, int value) {
        Node* cur = moveToHead(key);
        if (cur != nullptr) {
            cur->val = value;
        } else {
            cur = new Node();
            cur->key = key;
            cur->val = value;
            keyToNode[key] = cur;

            insertToHead(cur);
            cap--;

            if (cap == -1) {
                Node *cur = pt->pre;
                moveOut(cur);
                keyToNode.erase(cur->key);
                delete cur;
                cap++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */