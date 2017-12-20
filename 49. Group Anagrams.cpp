/*
把单词按照Anagrams（颠倒字母而成的字）分组
直接哈希判重按顺序丢就好。

*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<long long, int>mp;
        vector<vector<string>> ans;
        int cnt=0;
        for(int i=0;i<n;i++) {
            int len = strs[i].size();
            int c[128]={};
            for(int j=0;j<len;j++)
                c[strs[i][j]]++;
            long long hash = 0;
            for(int i=0;i<128;i++)
                hash = hash * 131 + c[i] + 1;
            if(!mp[hash]) {
                vector<string> tmp;
                mp[hash] = ++cnt;
                tmp.push_back(strs[i]);
                ans.push_back(tmp);
            } else {
                ans[mp[hash]-1].push_back(strs[i]);
            }
        }
        return ans;
    }
};