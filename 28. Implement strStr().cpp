/*
实现 strStr，
我直接写了个 O(mn)水过去的，正经写法应该写个 KMP 吧。

wa1，没考虑 needle 为""的情况，答案应该是0。
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for(int i=0;i+m<=n;i++) {
            bool match = true;
            for(int j=0;j<m;j++)
                if(haystack[i+j]!=needle[j]) {
                    match = false;
                    break;
                }
            if(match)
                return i;
        }
        return -1;
    }
};