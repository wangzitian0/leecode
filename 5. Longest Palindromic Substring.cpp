/*
求一个字符串的最长回文子串。
O(n^2)暴力做即可，进一步做可以曼彻斯特算法
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        pair<int, int>ans;
        for(int i=0;i<len*2-1;i++) {
            for(int j=i/2;j<len && i-j>=0 && s[j]==s[i-j] ;j++) {
                if (ans.second-ans.first<j+1-i+j)
                    ans=make_pair(i-j,j+1);
            }
        }
        return s.substr(ans.first, ans.second-ans.first);
    }
};