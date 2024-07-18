/**
11:45 - 11:55

just f[i][j]=f[i-1][j-1]+f[i-1][j]

 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        for(int i=0;i<numRows;i++) {
            ans[i].assign(i+1, 1);
            for(int j=1;j<i;j++) {
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans;
    }
};