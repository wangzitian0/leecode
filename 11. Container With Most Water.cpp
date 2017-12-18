/*
给一个数组，表示若干垂直于 x 轴的直线，(i, ai)，选择两条直线，和 x 轴相交用来装水，求最大体积。

首先，答案可以这样看，找一个高度 ai 作为边，然后平行于 x 轴分别往右侧延长，如果有高于自己的边，就可以形成一个装水容器。
显然，我们的目的是要找到最右侧高于自己的边。多画一下图就会发现一个规律，能形成答案的左边界左边必然没有高于自己的边，右边也是。
最终和答案相关的边呈凸型，且每条边对应的另一条边是唯一的，按照高度单调递增或递减来枚举，并找到对应边即可。
左右两个游标轮动的写法相对简洁一点。


WA1, 理解错题目意思了，刚开始理解成往里面灌水，最大的块是哪一个。比如[1,2,1]，理解成了答案是 1
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int ans = 0, ll=0, rr=len-1;
        while(ll<rr) {
            ans = max(ans, min(height[ll],height[rr])*(rr-ll));
            if(height[ll]<height[rr])
                ll ++;
            else
                rr --;
        }
        return ans;
    }
};