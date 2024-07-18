/**
10：35 - 10:45
my solution was very slow.
I believe lot of solution has bugs, which dont have a loop for right-left-left and left-right-right.


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
         Node* leftPtr = root->left;
         Node* rightPtr = root->right;
         while(leftPtr && rightPtr) {
             leftPtr->next = rightPtr;
             leftPtr = leftPtr->right;
             rightPtr = rightPtr->left;
         }
         connect(root->left);
         connect(root->right);
         return root;
     }
 };