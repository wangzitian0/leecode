/**
11:55 - 12:02

just f[i][j]=f[i-1][j-1]+f[i-1][j]

 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        for(int index=0;index<=rowIndex;index++) {
            vector<int>cur;
            cur.assign(index+1, 1);
            for(int i=1;i<index;i++) {
                cur[i]=ans[i]+ans[i-1];
            }
            ans = cur;
        }
        return ans;
    }
};