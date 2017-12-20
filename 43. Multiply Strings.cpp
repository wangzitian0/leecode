/*
高精度乘法

*/


class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>s;
        int len1 = num1.size(), len2=num2.size();
        for(int i=0;i<=len1+len2+2;i++)
            s.push_back(0);
        for(int i=0;i<len1-1-i;i++)
            swap(num1[i],num1[len1-1-i]);
        for(int j=0;j<len2-1-j;j++)
            swap(num2[j],num2[len2-1-j]);
        for(int i=0;i<len1;i++)
            for(int j=0;j<len2;j++) {
                s[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        for(int i=0;i<len1+len2+2;i++) {
            s[i+1]+=s[i]/10;
            s[i]%=10;
        }
        int p=len1+len2+2;
        while(s[p]==0&&p>0)p--;
        string str;
        for(;p>=0;p--)
            str+=(s[p]+'0');
        return str;
    }
};