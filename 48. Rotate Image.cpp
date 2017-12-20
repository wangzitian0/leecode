/*
哈哈哈哈哈哈，当年研究生上机复试我就出的这个题目…… 好像放第二题还是第三题很多人没做出来。。。。。


*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        for(int i=0;i<n/2;i++) {
            for(int j=0;j<(n+1)/2;j++) {
                //  0 1 -> 1 3 -> 3 2 -> 2 0
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};