/*
数字转罗马数字

没啥技巧，仔细看看 wiki 就好

Wa了无数次，发现理解还是有问题，匹配可能出现各种搭配，最后看题解了。
*/

class Solution {
public:
    int romanToInt(string s) {
        int num[128]={};
        num['I']=1;
        num['V']=5;
        num['X']=10;
        num['L']=50;
        num['C']=100;
        num['D']=500;
        num['M']=1000;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(i<n-1&&num[s[i]]<num[s[i+1]])
                ans -= num[s[i]];
            else
                ans += num[s[i]];
        }
        return ans;
    }
};