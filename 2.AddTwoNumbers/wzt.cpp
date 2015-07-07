class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>mp;
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            if(mp[target-nums[i]])
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i+1);
                return ans;
            }
            mp[nums[i]]=i+1;
        }
    }
};
