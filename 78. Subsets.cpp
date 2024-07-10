/*
10:35 - 10:40
1 ac
just 1 .. to 2^n
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<(1<<nums.size());i++) {
            vector<int>comb;
            for(int j=0;j<nums.size();j++)
                if((i>>j)&1) {
                    comb.push_back(nums[j]);
                }
            ans.push_back(comb);
        }
        return ans;
    }
};