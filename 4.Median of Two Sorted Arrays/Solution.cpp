
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size(),nm2=(n+m)/2;
        if(n>m)return findMedianSortedArrays(nums2, nums1);
        int ll=0,rr=n+1;
        while(ll+1!=rr)
        {
            int mid=(ll+rr)/2;
            int mi=0x7fffffff,ma=0xffffffff;
            if(mid>=0&&mid<n)mi=min(mi,nums1[mid]);
            if(nm2-mid>=0&&nm2-mid<m)mi=min(mi,nums2[nm2-mid]);
            if(mid-1>=0&&mid-1<n)ma=max(ma,nums1[mid-1]);
            if(nm2-mid-1>=0&&nm2-mid-1<m)ma=max(ma,nums2[nm2-mid-1]);
            //cout<<ll<<"-"<<mid<<"-"<<rr<<": min-"<<mi<<" max-"<<ma<<endl;
            if((mid!=0&&nums1[mid-1]<nums2[nm2-mid])||(mid!=n&&nums1[mid]<nums2[nm2-mid-1]))
                ll=mid;
            else rr=mid;
        }
        int mi=0x7fffffff,ma=0xffffffff,mid=ll;
        if(mid>=0&&mid<n)mi=min(mi,nums1[mid]);
        if(nm2-mid>=0&&nm2-mid<m)mi=min(mi,nums2[nm2-mid]);
        if(mid-1>=0&&mid-1<n)ma=max(ma,nums1[mid-1]);
        if(nm2-mid-1>=0&&nm2-mid-1<m)ma=max(ma,nums2[nm2-mid-1]);
        //return (min(nums1[ll],nums2[nm2-ll])+max(nums1[ll-1],nums2[nm2-ll-1]))*0.5;
        //cout<<ll<<"-"<<mid<<"-"<<rr<<": min-"<<mi<<" max-"<<ma<<endl;
        if((n+m)%2==0)
            return (mi+ma)*0.5;
        else
            return mi*1.0;
    }
};
int main()
{
    Solution x= Solution();
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    vector<int>v2;
    v2.push_back(2);
    v2.push_back(3);
    cout<<x.findMedianSortedArrays(v1,v2)<<endl;
}
