
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    string strs="";

    int N;
    void dfs(int cl,int cr)
    {
        if(cl<cr||cl>N||cr>N)return;
        if(cl==N&&cr==N)
        {
            ans.push_back(strs);
            return;
        }
        strs[cl+cr]='(';
        dfs(cl+1,cr);
        strs[cl+cr]=')';
        dfs(cl,cr+1);
    }
    vector<string> generateParenthesis(int n) {
        N=n;
        for(int i=0;i<N;i++)strs+="()";
        dfs(0,0);
        return ans;
    }
};

int main()
{
    Solution x= Solution();
}
