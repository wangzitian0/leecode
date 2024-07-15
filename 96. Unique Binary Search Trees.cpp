/*
12:00 - 12:02
just dp.

*/
class Solution {
public:
    int numTrees(int n) {
        // f[i]=sum(f[j]*f[i-1-j]);
        vector<int>ans(n+1,0);
        ans[0]=1;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<i;j++) {
                ans[i]+=ans[j]*ans[i-1-j];
            }
        }
        return ans[n];
    }
};