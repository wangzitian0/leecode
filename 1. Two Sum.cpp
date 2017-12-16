/*
给一个数组 A 和一个数字 P，在 A 中找两个数，让它和为 P。保证解唯一。

拿个 Map<数字，出现的位置> 装好每个数字对应的位置，扫描一遍之后可以有答案。
复杂度 O(N*map)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> position;
        vector<int>ans;
        int len = nums.size();
        for(int i=0;i<len;i++) {
            if (position[target-nums[i]]) {
                ans.push_back(position[target-nums[i]]-1);
                ans.push_back(i);
                break;
            } else {
                position[nums[i]]=i+1;
            }
        }
        return ans;
    }
};