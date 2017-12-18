/*
生成一个1-n^2的螺旋形矩阵。

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int fang[4][2]={0,1,1,0,0,-1,-1,0},f=0;
        vector<vector<int> > ans;
        for(int i=0;i<n;i++) {
            vector<int> line;
            for(int j=0;j<n;j++)
                line.push_back(0);
            ans.push_back(line);
        }
        int x=0,y=0;
        for(int k=1;k<=n*n;k++) {
            ans[x][y]=k;
            if(x+fang[f][0]<0||x+fang[f][0]>=n||y+fang[f][1]<0||y+fang[f][1]>=n||ans[x+fang[f][0]][y+fang[f][1]]!=0)
                f=(f+1)%4;
            x += fang[f][0];
            y += fang[f][1];
        }
        return ans;
    }
};