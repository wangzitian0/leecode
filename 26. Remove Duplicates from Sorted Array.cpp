/*
水题，一个有序数组，求不重复的数字个数。

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0, n=nums.size();
        for(int i=0;i<n;i++)
            if(i==0||nums[i]!=nums[i-1])
                nums[pos++]=nums[i];
        nums.erase(nums.begin()+pos,nums.end());
        return pos;
    }
};