
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int mi=0x3f3f3f3f;
        for(int i=0;i<strs.size();i++)
            mi=min(mi,(int)strs[i].length());
        if(mi==0x3f3f3f3f)return ans;
        for(int i=0;i<mi;i++)
        {
            int notsame=0;
            for(int j=1;j<strs.size();j++)
                if(strs[j][i]!=strs[j-1][i])
                    notsame=1;
            if(notsame)
                return ans;
            ans+=strs[0][i];
        }
        return ans;
    }
};

int main()
{
    Solution x= Solution();
}
