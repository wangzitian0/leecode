/*
spent half hour.

WA. tried binary search, [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1] 2

emmmmmm. all of the solution is O(n)

*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (auto num : nums) {
            if(num==target) {
                return true;
            }
        }
        return false;
    }
};
/*
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, up = nums.size();
        while(low+1<up) {
            int mid=(low+up)/2;
            if(nums[low]>nums[mid])
                up=mid;
            else low=mid;
        }
        int splitPos = low;
        // [0,splitPos],[splitPos+1,n)
        low = 0, up = splitPos+1;
        while(low+1<up) {
            int mid=(low+up)/2;
            if(nums[mid]>target)
                up=mid;
            else low=mid;
        }
        if(low<up&&nums[low]==target)return true;

        low = splitPos+1, up = nums.size();
        while(low+1<up) {
            int mid=(low+up)/2;
            if(nums[mid]>target)
                up=mid;
            else low=mid;
        }
        if(low<up&&nums[low]==target)return true;
        return false;
    }
};
*/