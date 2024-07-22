/**
5 min
WA1: "  hello world  "




 */
class Solution {
public:
    string reverseWords(string s) {
        int pre = -1;
        int sz = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != ' ' || (sz > 0 && s[sz - 1] != ' ')) {
                s[sz++] = s[i];
            }
        s.erase(s.begin() + sz, s.end());
        if (sz > 0 && s[sz - 1] == ' ')
            s.erase(s.end() - 1, s.end());
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + pre + 1, s.begin() + i);
                pre = i;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};