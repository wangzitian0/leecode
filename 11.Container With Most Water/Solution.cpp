
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ll=0,rr=height.size()-1,ans=0;
        while(ll<rr)
        {
            ans=max(ans,min(height[ll],height[rr])*(rr-ll));
            if(height[ll]>height[rr])
                rr--;
            else ll++;
        }
        return ans;
    }
};
int main()
{
    Solution x= Solution();
}
