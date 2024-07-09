/*
9:10 - 9:18
prefix sum - min(last prefix sum) is the answer.
*/
class Solution {
public:
    vector<int>pre_sum;
    int maxSubArray(vector<int>& nums) {
        int min_val=0, sum=0,ans=0x80000000;
        for(int i=0;i<nums.size();i++){
            cur_num = nums[i];
            sum+=cur_num;
            ans = max(ans, sum-min_val);
            min_val = min(min_val, sum);
        }
        return ans;
    }
};