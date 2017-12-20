/*
lower_bound() & upper_bound()
就是个二分，我按我自己的经典写法写的。但是初始值需要扩宽一些。
lower_bound()
我二分的东西是一条缝，缝夹在 low 和 up = low+1 里，
缝左边（<=low）的数字全部小于 target，缝右边(>=up)的数字全部大于等于 target
所以 low 的取值是 [-1,n-1], up 的取值是 [0,n]

  a1  a2 | a3  a4  a5
low   low|up        up

WA x2  数组为空和只有一个元素的情况出错了，因为我刚开始没仔细想区间的事情
随手打的[-1,n-1]，样例还一直能过，然后仔细想了下，分析就在上面

*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = -1, up = n;
        vector<int> ans;
        while(low+1<up) {
            int mid = (low+up)/2;
            // nums[low]<target && nums[up]>=target;
            if(nums[mid]<target)
                low = mid;
            else
                up = mid;
        }
        ans.push_back(up);

        low = -1, up = n;
        while(low+1<up) {
            int mid = (low+up)/2;
            // nums[low]<=target && nums[up]>target;
            if(nums[mid]<=target)
                low = mid;
            else
                up = mid;
        }
        ans.push_back(low);
        if(ans[0]>ans[1])
            ans[0]=ans[1]=-1;
        return ans;
    }
};