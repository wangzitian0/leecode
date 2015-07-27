
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<string> ans;
    string op;
    void dfs(int step,string str,string digits)
    {
        if(step==n)
        {
            if(str.length())ans.push_back(str);
            //cout<<str<<endl;
            return;
        }
        int num=digits[step]-'0';
        for(char i=op[num];i<op[num+1];i++)
        {
            dfs(step+1,str+i,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        n=digits.length();
        op="  adgjmptw";
        op+=(char)('z'+1);
        dfs(0,"",digits);
        return ans;
    }
};
int main()
{
    Solution x= Solution();
    x.letterCombinations("");
}
