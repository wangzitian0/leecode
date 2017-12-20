/*
lower_bound()

*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
        return up;
    }
};