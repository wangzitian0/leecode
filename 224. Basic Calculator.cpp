/**
19:05 - 19:35

spent lot of time on the index related part.
Just recursively got the val inside ().
then scan.
If there are '*' or '/', scan twice.
 */

class Solution {
private:
    int calculate(string s, int l, int r) { // s[l, r]
        vector<int> val;
        vector<char> op;
        val.push_back(0);
        vector<int> gPair(r - l + 1, 0);
        vector<int> stk;
        for (int i = l; i <= r; i++) {
            if (s[i] == '(') {
                stk.push_back(i - l);
            } else if (s[i] == ')') {
                gPair[stk.back()] = i;
                stk.pop_back();
            }
        }
        for (int i = l; i <= r; i++) {
            if (s[i] == '+' || s[i] == '-') {
                op.push_back(s[i]);
                val.push_back(0);
            } else if (s[i] >= '0' && s[i] <= '9') {
                int ch = s[i] - '0';
                val.back() = val.back() * 10 + ch;
            } else if (s[i] == '(') {
                val.back() = (calculate(s, i+1, gPair[i-l]-1));
                i=gPair[i-l];
            }
        }
        int ans = val[0];
        for (int i = 0; i < op.size(); i++)
            if (op[i]=='+'){
                ans += val[i+1];
            } else {
                ans -= val[i+1];
            }
        cout<<l<<"#"<<r<<"="<<ans<<endl;
        return ans;
    }

public:
    int calculate(string s) { return calculate(s, 0, s.size() - 1); }
};