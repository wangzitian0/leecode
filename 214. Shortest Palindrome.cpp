// insert to front side
// find the ans = max(i|s[0..i] is palindrome)

const long long hsMod = 1e9 + 7;
const long long hsBase = 1e5 + 9;
class Solution {
public:
    string shortestPalindrome(string s) {
        vector<long long> hash(s.size() + 1, 0);
        vector<long long> hashReverse(s.size() + 1, 0);
        vector<long long> po(s.size() + 1, 1);
        // hash[i,j) = hs[j]-hs[i]*po[j-i] % mod

        for (int i = 0; i < s.size(); i++) {
            hash[i + 1] = (hash[i] * hsBase + s[i]) % hsMod;
            po[i + 1] = po[i] * hsBase % hsMod;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            hashReverse[i] = (hashReverse[i + 1] * hsBase + s[i]) % hsMod;
        }
        // for (int i = 0; i <= s.size(); i++) {
        //     cout<<i<<":"<<hash[i]<<" "<<hashReverse[i]<<endl;
        // }
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            long long reverseHs =
                (hashReverse[0] - hashReverse[i + 1] * po[i + 1] % hsMod +
                 hsMod) %
                hsMod;
            // cout<<i<<"->"<<reverseHs<<endl;

            if (hash[i + 1] == reverseHs) {
                ans = max(ans, i);
            }
        }
        string resp = s;
        reverse(resp.begin(), resp.end());
        for (int i = ans + 1; i < s.size(); i++)
            resp += s[i];
        return resp;
    }
};