/*
水题，一个有序数组，求删掉某个元素之后的数组和数组长度。

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0, n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]!=val)
                nums[pos++]=nums[i];
        }
        nums.erase(nums.begin()+pos,nums.end());
        return pos;
    }
};