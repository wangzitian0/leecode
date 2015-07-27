
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),s,mi=0x7fffffff,ma=0x80000000;
        //cout<<ma<<endl;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1,k=n-1;j<k;)
            {
                s=nums[i]+nums[j]+nums[k];
                if(s>target)
                {
                    mi=min(mi,s);k--;
                }
                else if(s<target)
                {
                    ma=max(ma,s);j++;
                }
                else if(s==target)
                {
                    mi=ma=s;
                    while(++j<k&&nums[j+1]==nums[j]);
                    while(j<--k&&nums[k-1]==nums[k]);
                }
            }
            while(nums[i]==nums[i+1])i++;
        }
        if((long long) mi+ma-2*target<0)
            return mi;
        else return ma;
    }
};
int main()
{
    Solution x= Solution();
}
