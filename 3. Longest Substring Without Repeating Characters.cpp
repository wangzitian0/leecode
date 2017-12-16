/*
给一个字符串，找到没有重复字母的最长子串。

双游标扫描，从左到右扫描，右游标主动移动，左游标懒移动且移动的时候确保两个游标中间没有重复字母。
每个元素只会被扫描一次，复杂度 O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128]={};
        int len = s.size();
        int ans = 0;
        for(int r=0,l=0;r<len;r++) {
            cnt[s[r]]++;
            while(cnt[s[r]]>1) {
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};