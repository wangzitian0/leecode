/*
一个数字代表一个连续区间的海拔，求这个区间形成的挡板最多装多少水。
首先，答案肯定是 sum{ min(lmax[i],rmax[i])-height[i] }
lmax[i] 表示[0,i]的最高值
lmax[i] 表示 [i,n)的最高值
扫一扫就好了

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        vector<int>lmax(n,0);
        vector<int>rmax(n,0);
        for(int i=0;i<n;i++) {
            lmax[i]=height[i];
            if(i)
                lmax[i]=max(lmax[i], lmax[i-1]);
        }
        for(int i=n-1;i>=0;i--) {
            rmax[i]=height[i];
            if(i!=n-1)
                rmax[i]=max(rmax[i], rmax[i+1]);
        }
        for(int i=0;i<n;i++) {
            ans += min(lmax[i], rmax[i]) - height[i];
        }
        return ans;
    }
};