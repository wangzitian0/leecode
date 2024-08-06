/**
18:35 - 18:45
use two stack.
curVal 5 3 2 1 4
minVal 5 3 2 1 1

retrieve it by:
minVal[sz] = min(minVal[sz], minVal[sz - 1]);
the minVal won't change as long as it was added to the list.

 */

class MinStack {
private:
    vector<int> curVal;
    vector<int> minVal;

public:
    MinStack() {}

    void push(int val) {
        curVal.push_back(val);
        minVal.push_back(val);
        int sz = minVal.size();
        if (sz > 1) {
            minVal[sz - 1] = min(minVal[sz - 1], minVal[sz - 2]);
        }
    }

    void pop() {
        curVal.pop_back();
        minVal.pop_back();
    }

    int top() { return curVal[curVal.size() - 1]; }

    int getMin() { return minVal[minVal.size() - 1]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */