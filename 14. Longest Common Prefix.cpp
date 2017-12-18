/*
给你 n 个字符串，求它们的公共最长前缀。

Wa1, 代码没处理["a"]
Wa2, 代码没处理[]
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans = 0x7fffffff, n=strs.size();
        for(int i=0;i<n;i++)
            ans = min(ans, (int)strs[i].size());
        if(ans == 0x7fffffff)return "";
        for(int i=0;i<ans;i++) {
            int z=0;
            for(int j=1;j<n;j++)
                if(strs[j][i]!=strs[0][i])
                    z=1;
            if(z) {
                ans = i;
            }
        }
        string str="";
        for(int i=0;i<ans;i++)
            str += strs[0][i];
        return str;
    }
};