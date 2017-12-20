/*
快速幂，之前刷过这个，注意负数就好。

*/


class Solution {
public:
    double myPow(double x, int n) {
        if(n==1)return x;
        if(n==-1)return 1.0/x;
        if(n==0)return 1.0;
        double tmp = myPow(x, n/2);
        tmp *= tmp;
        tmp *= myPow(x, n%2);
        return tmp;
    }
};