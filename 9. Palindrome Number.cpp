/*
判断一个 int 是不是回文数

负数特别处理一下，如果不处理，类似-11之类的数据可能出错。

*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int pos[10] = {}, p = 0;
        while(x) {
            pos[p++] = x%10;
            x /= 10;
        }
        for(int i=0;i<p-1-i;i++)
            if(pos[i]!=pos[p-1-i])
                return false;
        return true;
    }
};