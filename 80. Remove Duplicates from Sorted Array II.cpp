/*
11:05 - 11:30
Sh*t index handling.
Can not use unique()
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans_pos=0,cur_pos=0,cnt=0;
        while(cur_pos<nums.size()) {
            int tar_pos = cur_pos+1;
            while(tar_pos<nums.size()) {
                if (nums[tar_pos]!=nums[cur_pos])
                    break;
                tar_pos++;
            }
            cnt = tar_pos-cur_pos;
            if(cnt>2)cnt=2;
            while(cnt>0) {
                nums[ans_pos] = nums[cur_pos];
                ans_pos++;
                cur_pos++;
                cnt--;
            }
            cur_pos = tar_pos;
        }
        nums.erase(nums.begin()+ans_pos,nums.end());
        return nums.size();
    }
};