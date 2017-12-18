/*
给 n 个数，找4个使得和为0。
输出所有不同的答案组。


和3sum 差不多。
wa 了几下，原因是不能用 O(n^2)的方法去分段哈希（两两组合，形成n^2个哈希值），可能存在情况两组两个数的和一样，这种时候方案却是不同的。

wa 哈希判重的函数没有从3改到4
TLE， 最内层我套了一个排序，但是实际上没有必要，必然是  map 里的数字< nums[i] < nums[j] < nums[k]

*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int,int>numsp;
        int n = nums.size();
        for(int i=0;i<n;i++)
            numsp[nums[i]] += 1;
        nums.erase(nums.begin(),nums.end());
        n=0;
        for(map<int,int>::iterator it=numsp.begin();it!=numsp.end();it++) {
            for(int i=0;i<min(4,it->second);i++)
                nums.push_back(it->first);
            n += min(4,it->second);
        }

        vector<vector<int>> ans;
        ans.reserve(10000);
        unordered_set<long long>asp;
        unordered_set<int>mp;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if(mp.find(nums[i]+nums[j]+nums[k])!=mp.end()) {
                        vector<int> tmp;
                        tmp.push_back(target-nums[i]-nums[j]-nums[k]);
                        tmp.push_back(nums[k]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[i]);
                        // sort(tmp.begin(),tmp.end());
                        long long z=0;
                        for(int k=0;k<4;k++)
                            z=z*999999997+tmp[k];
                        if(asp.find(z)==asp.end()) {
                            asp.insert(z);
                            ans.push_back(tmp);
                        }
                    }
                }
            }
            mp.insert(target-nums[i]);
        }
        // sort(ans.begin(), ans.end());
        // ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};