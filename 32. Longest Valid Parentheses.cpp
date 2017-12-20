/*
想了很久。
第一反应是要找一个 O(n) 的扫描线算，画出一个类似二维坐标的东西，x 轴为下标，y 轴如果是'(',+1;')'-1;
会形成一个图像，然后画一根平行于 x 轴的横线，与上凸的图像相交出两个点，最大的 x 坐标差就是答案。

敲了半天发现不用这么复杂。

直接一个栈去扫描就好。'('把坐标压入栈，')'出栈的时候栈里的坐标和当前坐标之差就是一个区间。
然后麻烦事是如何处理连在一起的多个序列'(())()()'，这个地方我敲了好久……
想清楚之后其实很简单，栈里面可以压一个虚拟元素表示第一个失配的')'，一旦出现失配之后的答案的起始坐标一定不会早于这个失配坐标。
对于0的处理也是一样，加-1节点相当于在-1位置加一个')'

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        stack<int>stk;
        int last = 0;
        stk.push(-1);
        for(int i=0;i<n;i++) {
            if (s[i]=='(') {
                stk.push(i);
            }
            else if (s[i]==')') {
                stk.pop();
                if(!stk.empty()) {
                    ans = max(ans, i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }
        return ans;
    }
};