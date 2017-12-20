/*
不适用乘法除法取模，实现一个除法。


wa1，两个数字都有可能为负。
wa2,-2147483648/-1 , ans = 2147483647
wa3, -2147483648/1 , ans = -2147483648
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long fz=dividend, fm=divisor;
        int f=1;
        if(fm<0)fz=-fz, fm=-fm;
        if(fz<0)f=-1,fz=-fz;
        long long po[64]={}, pos=0;
        po[0]=fm;
        while(po[pos]+po[pos]<=fz) {
            po[pos+1]=po[pos]+po[pos];
            pos++;
        }
        long long ans=0;
        for(int i=pos;i>=0;i--) {
            if(fz>=po[i])
                ans|=(1LL<<i), fz-=po[i];
        }
        if(f==-1)ans = -ans;
        if(ans-0x7fffffff>0||ans+0x7fffffff+1<0)
            return 0x7fffffff;
        return ans;
    }
};