/**
20:54 - 20:55
just scan.

 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> h(128, 0);
        for (auto ch : s) {
            h[ch]++;
        }
        for (auto ch : t) {
            h[ch]--;
        }
        for (int i = 0; i < 128; i++) {
            if (h[i] != 0) {
                return false;
            }
        }
        return true;
    }
};