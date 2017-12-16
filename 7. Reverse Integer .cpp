/*
倒转一个整数，如果不合法输出0

水题，注意下几个重要边界，包括 x10的时候大小判断，0xFFFFFFFF 返回0.
*/
class Solution {
public:
    int reverse(int x) {
        int ans=0, f=1;
        if(x==0xFFFFFFFF)return 0;
        if(x<0)f=-1, x=-x;
        while(x>0) {
            if(ans <= 0x7FFFFFFF/10 && ans*10 <= 0x7FFFFFFF - x%10)
                ans = ans*10 + x%10;
            else
                return 0;
            x=x/10;
        }
        return ans*f;
    }
};