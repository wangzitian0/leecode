/*
12:19 - 12:26
just dp.
index used lots of time.
f[i][j] represent the gap will be easier
    a b c
i= 0 1 2 3

WA: a very special case len(s1)+len(s2)!=len(s3)
added a if then passed.

*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>>ans(s1.size()+1,vector<bool>(s2.size()+1,0));
        ans[0][0]=true;
        for(int i=0;i<=s1.size();i++)
            for(int j=0;j<=s2.size();j++) {
                if (ans[i][j]) {
                    if (i+1<=s1.size()&&s1[i]==s3[i+j]) {
                        ans[i+1][j]=true;
                    }
                    if (j+1<=s2.size()&&s2[j]==s3[i+j]) {
                        ans[i][j+1]=true;
                    }
                }
            }
        if(s3.size()!=s1.size()+s2.size())
            return false;
        return ans[s1.size()][s2.size()];
    }
};