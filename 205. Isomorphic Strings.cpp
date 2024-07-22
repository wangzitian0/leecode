/**
5 min
WA1: it need reverse mapping also. I only one map in the first time.
case 'babc'  'baba'

 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char g[128] = {}, h[128] = {};
        for (int i = 0; i < s.size(); i++) {
            if (g[s[i]] == 0) {
                g[s[i]] = t[i];
            }
            if (h[t[i]] == 0) {
                h[t[i]] = s[i];
            }
            if (g[s[i]] != t[i] || h[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};