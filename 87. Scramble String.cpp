/*
about 50min
Just DP, but the index used lots of time.
And check indexes used 10min.
see the comment.

*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        // f[l][i][j]=true find a match{s1[i,i+l),s2[j,j+l)}
        // for the k=left string length,
        // case 1: match{s1[i,i+k),s2[j,j+k)}  && match{s1[i+k,i+l)==s2[j+k,j+l)
        // case 2: match{s1[i,i+k),s2[j+l-k,j+l)} && {match(s1[i+k,i+l)==s2[j,j+l-k)}
        vector<vector<vector<bool>>>dp(n+1,
            vector<vector<bool>>(n,
                vector<bool>(n,false)));

        for(int l=1;l<=n;l++) {
            for(int i=0;i+l<=n;i++) {
                for(int j=0;j+l<=n;j++) {
                    if (l==1&&s1[i]==s2[j])
                        dp[l][i][j]=true;
                    for(int k=1;k<l;k++) {
                        dp[l][i][j]=dp[l][i][j] ||
                            (dp[k][i][j]&&dp[l-k][i+k][j+k]) ||
                            (dp[k][i][j+l-k]&&dp[l-k][i+k][j]);
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};