/*
10:02 -10:19
Just DP, usd ans[i] represent the number of choice.

*/

class Solution {
public:
    int numDecodings(string s) {
        // f[i] = f[i-1] + f[i-2]{iff 1<=s[i-1,i-2]<=26}
        vector<int>ans(s.size()+1,0);
        ans[0]=1;
        for(int i=1;i<=s.size();i++) {
            int curNum = s[i-1]-'0';
            if(curNum>=1&&curNum<=9)
                ans[i]+=ans[i-1];
            if(i==1)continue;
            curNum += 10*(s[i-2]-'0');
            if(curNum>=10&&curNum<=26)
                ans[i]+=ans[i-2];
        }
        return ans[s.size()];
    }
};