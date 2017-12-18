/*
给 n 个数，找三个数，使得他们之和最接近 T。

Wa了两次，原因是lower_bound的接口不记得了，然后想着想着就想歪了。
目的是找到 Set 里第一个大于等于 T 的数字和第一个小于等于 T 的数字，这种操作不能用 upper_bound，
应该用完 lower_bound 之后，迭代器--。

另外还发现一个事情，unordered_map不能直接用 pair 当 key，需要自己实现一个 hash 的函数。
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

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

        int ans = nums[0]+nums[1]+nums[2], dis = abs(ans-target);
        set<int>mp;
        set<int>::iterator it;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                it = mp.lower_bound(target-nums[j]-nums[i]);
                if(it!=mp.end()&&abs(*it+nums[j]+nums[i]-target)<dis) {

                    ans = *it+nums[j]+nums[i], dis = abs(*it+nums[j]+nums[i]-target);
                }
                if(it==mp.begin())continue;
                it--;

                if(abs(*it+nums[j]+nums[i]-target)<dis) {
                    ans = *it+nums[j]+nums[i], dis = abs(*it+nums[j]+nums[i]-target);

                }
            }
            mp.insert(nums[i]);
        }
        // sort(ans.begin(), ans.end());
        // ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
