/*
8:42 - 8:50


*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n==0)return;
        int m = matrix[0].size();
        if (m==0)return;
        vector<bool>col(m,0),row(n,0);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]==0) {
                    row[i]=true;
                    col[j]=true;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (row[i]||col[j]) {
                    matrix[i][j]=0;
                }
            }
        }
        return;
    }
};