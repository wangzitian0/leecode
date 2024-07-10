/*
8:33-8:42

WA 1.
ignore the cass "","aaa"

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,1e9));
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++) {
                if(i&&j&&word1[i-1]==word2[j-1]) {
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                } else if(i&&j){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                }
                if(j)dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                if(i)dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            }
        return dp[n][m];
    }
};