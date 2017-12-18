/*
给定一个旋转后的升序数组，4 5 6 7 0 1 2。
查询一个数字。

先二分出分隔符div，如上面例子里的7 0，然后分段二分，看是否出现。

WA1, 没有考虑 nums 为空的情况
WA2，最后没有查询的时候，没有返回-1.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = -1, up = n-1;
        while(low+1<up) {
            int mid = (low + up) / 2;
            if(nums[mid]>=nums[0])
                low = mid;
            else
                up = mid;
        }
        // [0, up), [up, n)
        int div = up;
        if(div<0)return -1;

        low = 0, up = div;
        while(low+1<up) {
            int mid = (low + up) / 2;
            if(nums[mid]<=target)
                low = mid;
            else
                up = mid;
        }
        if(nums[low]==target)
            return low;

        low = div, up = n;
        while(low+1<up) {
            int mid = (low + up) / 2;
            if(nums[mid]<=target)
                low = mid;
            else
                up = mid;
        }
        if(nums[low]==target)
            return low;
        return -1;
    }
};