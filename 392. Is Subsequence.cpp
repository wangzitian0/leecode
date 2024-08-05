/**
20:10 - 20:30
just scan
WA1: ignore the s=='' case.

 */


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) {
            return true;
        }
        int matchIndex = 0;
        for (int i = 0; i < t.size(); i++) {
            char ch = t[i];
            if (s[matchIndex]==ch) {
                matchIndex++;
                if (matchIndex==s.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};