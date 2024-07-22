/**
5 min
WA 1 'jq' 'jq'
forget the case that pi == pattern.size(); in the end.


 */
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string pToS[128];
        map<string, char> sToP;
        string cur;
        int pi = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                if (sToP[cur] == 0)
                    sToP[cur] = pattern[pi];
                if (pToS[pattern[pi]] == "")
                    pToS[pattern[pi]] = cur;
                if (sToP[cur] != pattern[pi] || pToS[pattern[pi]] != cur) {
                    return false;
                }
                cur = "";
                pi++;
            } else {
                cur += s[i];
            }
        }
        return pi == pattern.size();
    }
};