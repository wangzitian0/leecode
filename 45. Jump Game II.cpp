/*
给一个数组，假设你在 A[i], 每次可以向右跳 1->A[i]步，初始点是0，求最少几步跳到 n-1

一眼方程是
f[k]=min(f[i]+1); 满足  1<k<=A[i]
这是个 O(n^2)的搞法，如果是这样肯定不是 hard，接着想。。。。

想办法每个点的值只维护一次。
首先是，不存在两个点 i j 满足 i<j ，且从0跳到 j 的次数小于跳到 i 的次数，因为我只需要中途别跳满就能用同样的次数到更近的地方。
如果两个点 i j 满足 i<j && i+A[i]>=j+A[j], 那么[i+1, i+A[i]]的答案都是由 i来产生。
所以现在需要处理的只有一种数据 i<j && i+A[i]<j+A[j]，

进一步思考，可以拿一个数组去记录 K 步最远能跳到哪里。
更新每个节点的时候，从数组中查询最少多少步能跳到当前位置，然后去更新+1步最远跳到哪里。

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), cur = 0;
        vector<int>stk(n,0);
        for(int i=0;i<n;i++) {
            while(stk[cur]<i)cur++;
            stk[cur+1]=max(stk[cur+1], i+nums[i]);
        }
        return cur;
    }
};