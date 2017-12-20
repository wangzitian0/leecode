/*
给一个字符串 S，和一个词语长度相同的词语列表 L，求出现在 S 中的子串下标，子串满足由且仅由 L 中每个词语出现1次连接而成。

首先是字符串的处理，我是使用哈希，具体的公式是这样，可以用 O(len)的时间预处理， O(1) 的时间查询任何一个子串的哈希值
   C0     C1     C2   ...   Cn-3     Cn-2    Cn-1
   c0 +z*(c1 +z*(c2 +z*...  cn-3 +z*(cn-2 +z*cn-1)))
                 c2 +z*...  cn-3 +z*(cn-2 +z*cn-1

   H(i,j) = G[i] - G[j]*z^(j-i)

然后是处理这个问题转化为，给定一个数组，找一个连续区间[l,r)，每个数字在这个区间的出现次数值统计为 cnt[i],
对字符串集合L 也进行同样的统计，出现次数结果为mp[i]，求所有集合 cnt===mp 的 l 下标。
*/


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int slen = s.size(), n = words.size();
        int wlen = words[0].size();
        vector<long long >hash(slen+1,0);
        vector<long long >po(slen+1,0);
        for(int i=slen-1;i>=0;i--)
            hash[i] = hash[i+1] * 131 + s[i] + 1;
        unordered_map<long long, int> mp;
        po[0] = 1;
        for(int i=1;i<=slen;i++)
            po[i]=po[i-1]*131;
        for(int j=0;j<n;j++) {
            long long hs = 0;
            for(int i=wlen-1;i>=0;i--)
                hs = hs * 131 + words[j][i] + 1;
            mp[hs]++;
        }
        // Hash[i,j)   =  hash[i] - po[i-j] * hash[j];
        vector<int>ans;
        for(int s=0;s<wlen;s++) {
            unordered_map<long long, int> cnt;
            int tot=0, l=s;
            for(int r=s;r+wlen<=slen;r+=wlen) {
                long long rhash = hash[r] - po[wlen] * hash[r+wlen];
                cnt[rhash]++;
                tot++;
                while(cnt[rhash]>mp[rhash]) {
                    long long lhash = hash[l] - po[wlen] * hash[l+wlen];
                    l+=wlen;
                    cnt[lhash]--;
                    tot--;
                }
                if(tot==n) {
                    ans.push_back(l);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};