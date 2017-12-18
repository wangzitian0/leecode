/*
给 n 个数，找三个使得和为0。
输出所有不同的答案组。

Wa1, 代码没处理[0,0,0]
TLE了无数发，卡常数卡得紧，打了无数补丁，各种数据去重之类。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int>numsp;
        int n = nums.size();
        for(int i=0;i<n;i++)
            numsp[nums[i]] += 1;
        nums.erase(nums.begin(),nums.end());
        n=0;
        for(map<int,int>::iterator it=numsp.begin();it!=numsp.end();it++) {
            for(int i=0;i<min(3,it->second);i++)
                nums.push_back(it->first);
            n += min(3,it->second);
        }

        vector<vector<int>> ans;
        unordered_set<long long>asp;
        unordered_set<int>mp;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(mp.find(nums[i]+nums[j])!=mp.end()) {
                    vector<int> tmp;
                    tmp.push_back(-nums[i]-nums[j]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[i]);
                    sort(tmp.begin(),tmp.end());
                    long long z=0;
                    for(int k=0;k<3;k++)
                        z=z*999999997+tmp[k];
                    if(asp.find(z)==asp.end()) {
                        asp.insert(z);
                        ans.push_back(tmp);
                    }
                }
            }
            mp.insert(-nums[i]);
        }
        // sort(ans.begin(), ans.end());
        // ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};