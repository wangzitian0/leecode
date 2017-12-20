/*
给定一个数独棋盘，求一个合法的数独，保证解是唯一的。


数据真的弱，随手写一发就过了。。。。。。
正经解法应该是 DLX，反正肯定能构造出有唯一解且搜索时间特别长的数据。
棋盘判定直接用的上一个答案的，判定部分最好是用一用位运算，这样常数可以从 O(9x9)变成 O(9)

*/
class Solution {
public:
    int f = 0;
    vector<vector<char>> _ans;

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
    void dfs(int p, int q, vector<vector<char>>& board){
        if(q==9) {
            _ans = board;
            return;
        }
        if(p==9) {
            dfs(0, q+1, board);
            return;
        }
        if(board[p][q]!='.') {
            dfs(p+1, q, board);
            return;
        }
        for(char i='1';i<='9';i++) {
            board[p][q]=i;
            if(isValidSudoku(board))
                dfs(p+1, q, board);
            board[p][q]='.';
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(0, 0, board);
        board = _ans;
    }
};