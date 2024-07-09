/*
old problem
8:15 - 9:00
Same with the n-queen problem 1
*/

class Solution {
private:
    vector<int>row,col,cross,cross_reverse;
    void gen(int level, int n, int &output) {
        if(level==n+1) {
            //get the ans.
            output++;
            return; //
        }
        // in the level n, put i=1...n
        for (int i=1;i<=n;i++){
            // put queen in (level, i)
            row[level]=i;
            col[i]++;
            cross[level+i]++;
            cross_reverse[n+level-i]++;
            if(col[i]<=1 && cross[level+i]<=1 && cross_reverse[n+level-i]<=1)
                gen(level+1, n, output);
            // revert judge.
            cross[level+i]--;
            cross_reverse[n+level-i]--;
            col[i]--;
            row[level]=0;
        }
        // put nothing.
        // gen(level+1, n);
    }
public:
    int totalNQueens(int n) {
        row.resize(n+1);
        col.assign(n+1,0);
        cross.assign(2*n+1,0);
        cross_reverse.assign(2*n+1,0);
        int output;
        // Output sizes for debugging

        gen(1,n,output);
        return output;
    }
};