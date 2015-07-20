
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char ch[100][5]={"","I","II","III","IV","V","VI","VII","VIII","IX","","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","","M","MM","MMM"};
    int po[5]={1,10,100,1000,10000};
    int romanToInt(string s) {
        int sum=0;
        if(strstr(s.c_str(),"IV")){sum-=2;}
        if(strstr(s.c_str(),"IX")){sum-=2;}
        if(strstr(s.c_str(),"XL")){sum-=20;}
        if(strstr(s.c_str(),"XC")){sum-=20;}
        if(strstr(s.c_str(),"CD")){sum-=200;}
        if(strstr(s.c_str(),"CM")){sum-=200;}

        for(int i=0;i<s.length();i++){
            if(s[i]=='M') sum+=1000;
            if(s[i]=='D') sum+=500;
            if(s[i]=='C') sum+=100;
            if(s[i]=='L') sum+=50;
            if(s[i]=='X') sum+=10;
            if(s[i]=='V') sum+=5;
            if(s[i]=='I') sum+=1;

        }

        return sum;
    }
};
int main()
{
    Solution x= Solution();
    cout<<x.romanToInt("MDCCCLXXXIV")<<endl;
}
