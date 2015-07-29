
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')stk.push(s[i]);
            else if(s[i]==')'&&!stk.empty()&&stk.top()=='(')stk.pop();
            else if(s[i]==']'&&!stk.empty()&&stk.top()=='[')stk.pop();
            else if(s[i]=='}'&&!stk.empty()&&stk.top()=='{')stk.pop();
            else stk.push(s[i]);
        }
        return stk.empty();
    }
};
int main()
{
    Solution x= Solution();
    return 0;
}
