
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        vector< vector <int> >g;
        vector <int>gx;
        int lens=s.length(),lenp=p.length();
        for(int j=0;j<=lenp+1;j++)
            gx.push_back(false);
        for(int i=0;i<=lens+1;i++)
            g.push_back(gx);
        //cout<<1<<endl;
        g[0][0]=true;
        for(int i=0;i<=lens;i++)
            for(int j=0;j<=lenp;j++)
            {
                if(s[i]==p[j]||s[i]=='.'||p[j]=='.')g[i+1][j+1]|=g[i][j];

                if(s[i+1]=='*'&&i+1<lens)
                {
                    g[i+2][j]|=g[i][j];
                    if(s[i]==p[j]||s[i]=='.')
                        g[i][j+1]|=g[i][j];
                }

                if(p[j+1]=='*'&&j+1<lenp)
                {
                    g[i][j+2]|=g[i][j];
                    if(s[i]==p[j]||p[j]=='.')
                        g[i+1][j]|=g[i][j];
                }
            }
        /*for(int i=0;i<=lens;i++,printf("\n"))
            for(int j=0;j<=lenp;j++)
                printf("%d ",g[i][j]);*/
        return g[lens][lenp];
    }
};
int main()
{
    Solution x= Solution();
    cout<<x.isMatch("aa","")<<endl;
}
