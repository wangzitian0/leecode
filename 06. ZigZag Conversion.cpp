/*
按某种顺序把一个字符串扔到一个二维矩阵，然后遍历二维矩阵。

直接看准下标弄就可以了，复杂度是 O(n).
WA1: numRows不能为1
WA2：string ans(100, 0);这个语法好像不能这么用。
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        int len = s.size();
        string ans;
        int delta = numRows*2-2;
        for(int j=0;j<numRows;j++) {
            for(int i=0;i<len;i+=delta) {
                if (j!=numRows-1 && i+j<len)
                    ans += s[i+j];
                if (j!=0 && i+delta-j<len)
                    ans += s[i+delta-j];
            }
        }
        return ans;
    }
};