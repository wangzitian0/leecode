/*
给定一个数独棋盘，判断已经填入的数字是不是合法

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int h[9][9]={} ,v[9][9]={} , z[9][9]={};
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j] != '.') {
                    h[i][board[i][j]-'1']++;
                    v[j][board[i][j]-'1']++;
                    z[i/3*3+j/3][board[i][j]-'1']++;
                }
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(h[i][j]>1||v[i][j]>1||z[i][j]>1)
                    return false;
        return true;
    }
};