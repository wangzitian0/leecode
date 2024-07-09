/*
9:20 -
9:34 RE.
9:43 ac.
>n vs >=n got wrong.
*/
class Solution {
public:
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int cur_x=0, cur_y=-1,last_dir = 0;
        int n=matrix.size();
        if(n == 0) {return ans;}
        int m=matrix[0].size();
        if(m == 0) {return ans;}
        vector<vector<bool>>visited;
        visited.resize(n, std::vector<bool>(m, false));

        for(int step = 0;step<n*m;step++){
            for(int i=0;i<4;i++) {
                int cur_dir = (last_dir+i)%4;
                int next_x = cur_x + dir[cur_dir][0];
                if(next_x<0||next_x>=n) continue;
                int next_y = cur_y + dir[cur_dir][1];
                if(next_y<0||next_y>=m) continue;
                if(!visited[next_x][next_y]){
                    last_dir = cur_dir;
                    visited[next_x][next_y] = true;
                    ans.push_back(matrix[next_x][next_y]);
                    cur_x = next_x;
                    cur_y = next_y;
                    break;
                }
            }
        }
        return ans;
    }
};