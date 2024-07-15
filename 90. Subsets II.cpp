/*
9:45 - 10:02
just 0 -> 2^n
than, use a map to reduce repeated combination.

*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        unordered_map<long long,bool>ans_set;
        for(int i=0;i<(1<<nums.size());i++) {
            vector<int>cur;
            long long hash=0;
            for (int j=0;j<nums.size();j++) {
                if((i>>j)&1) {
                    cur.push_back(nums[j]);
                    hash = (hash*9997)+nums[j]+0x7FFFFFFFF;
                    hash %=999999997;
                }
            }
            if(!ans_set[hash]) {
                ans_set[hash]=true;
                ans.push_back(cur);
            }
        }
        return ans;
    }
};