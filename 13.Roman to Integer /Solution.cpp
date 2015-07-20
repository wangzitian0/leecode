
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char ch[100][5]={"","I","II","III","IV","V","VI","VII","VIII","IX","","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","","M","MM","MMM"};
    string intToRoman(int num) {
        string str="";
        for(int i=0;num;i++)
        {
            str=ch[i*10+num%10]+str;
            num/=10;
        }
        return str;
    }
};
int main()
{
    Solution x= Solution();
    cout<<x.intToRoman(3999)<<endl;
}
