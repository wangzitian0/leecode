/*
8:50 - 9:00
hard to understand the problem...
just binary search.

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n==0) return false;
        int m = matrix[0].size();
        if (m==0) return false;
        // pos = i*m+j;
        // i,j = pos/m, pos%m;
        int low=0, up=n*m;
        while(low+1<up) {
            int mid = (low+up)/2;
            int x = mid/m, y = mid%m;
            if (matrix[x][y]>target) {
                up = mid;
            } else low = mid;
        }
        return target==matrix[low/m][low%m];
    }
};