/*
old problem
8:15 - 9:00
第一发 RE。
递归的函数没有 return。。
*/

class Solution {
private:
    vector<int>row,col,cross,cross_reverse;
    void gen(int level, int n, vector<vector<string>>& output) {
        if(level==n+1) {
            //get the ans.
            vector<string> ans;
            for (int i=1;i<=n;i++) {
                string str(n, '.');
                str[row[i]-1]='Q';
                ans.push_back(str);
            }
            output.push_back(ans);
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
    vector<vector<string>> solveNQueens(int n) {
        row.resize(n+1);
        col.assign(n+1,0);
        cross.assign(2*n+1,0);
        cross_reverse.assign(2*n+1,0);
        vector<vector<string>> output;
        // Output sizes for debugging

        gen(1,n,output);
        return output;
    }
};