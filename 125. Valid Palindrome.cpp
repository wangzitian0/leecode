/**
    // 20:00- 20:18

    // wa for "0P" by 'removing all non-alphanumeric characters'

 */

class Solution {
private:
    inline bool isAlphanumeric(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return true;
        } else if (ch >= 'a' && ch <= 'z') {
            return true;
        } else if (ch >= '0' && ch <= '9') {
            return true;
        } else {
            return false;
        }
    }
    inline char toLowercase(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + 'a';
        }
        return ch;
    }

public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isAlphanumeric(s[l]))
                l++;
            while (l < r && !isAlphanumeric(s[r]))
                r--;
            if (toLowercase(s[l]) != toLowercase(s[r])) {
                return false;
            } else {
                l++;
                r--;
            }
        }
        return true;
    }
};