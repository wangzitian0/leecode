/*
10:42 - 10:57
just a dfs.

1. TLE...

2. no idea.
take a took at the solution
AC by
string word,vector<vector<char>>board
vs
const string& word,const vector<vector<char>>& board
f**k.

*/
class Solution {
private:
    vector<vector<bool>>used;
    int dir[4][2]={1,0,0,1,-1,0,0,-1};
    int n,m;
    bool dfs(int x, int y,int level,
      const string& word,const vector<vector<char>>& board) {
        if(word[level]!=board[x][y])return false;
        if(level==word.size()-1)return true;
        used[x][y]=true;
        for(int i=0;i<4;i++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (dx<0 || dx>=n)continue;
            if (dy<0 || dy>=m)continue;
            if (!used[dx][dy]&&dfs(dx,dy,level+1,word,board)) {
                return true;
            }
        }
        used[x][y]=false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        used.assign(n,vector<bool>(m,false));
        for(int i=0;i<n*m;i++) {
            if(dfs(i/m,i%m,0,word,board))
                return true;
        }
        return false;
    }
};