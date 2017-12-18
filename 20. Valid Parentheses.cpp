/*
判断一个包含大中小三种括号的序列是否合法。

拿个栈判一判就好了

WA1, 没处理']'，栈里面为空的情况。
*/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>stk;
        for(int i=0;i<n;i++) {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                stk.push(s[i]);
            else if(s[i]==')') {
                if(stk.size()>0&&stk.top()=='(')
                    stk.pop();
                else return false;
            }
            else if(s[i]==']') {
                if(stk.size()>0&&stk.top()=='[')
                    stk.pop();
                else return false;
            }
            else if(s[i]=='}') {
                if(stk.size()>0&&stk.top()=='{')
                    stk.pop();
                else return false;
            }
        }
        return stk.size()==0;
    }
};

