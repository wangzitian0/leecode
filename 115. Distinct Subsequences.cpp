/**
09:27 - 10:23
got the dp idea at the beginning, some kind of pre sum.
the index order take lots of time.
try to use 1 vector to calc all.
block point-> index left to right, when I got the cur[i], cur[i]has been changed.
used two vector to rotate.
WA1: the sum used long long. might special case like aaaaaab,aaaaaab, mid result can be big.
// a strict way should drop {value>0x80000000}

 */
class Solution {
public:
    int numDistinct(string s, string t) {
        //_             10000000
        // b    babgbag 01010100
        // ba           00100030
        // bag          00001004
        vector<long long>curSum(s.size()+1, 0), preSum(s.size()+1, 0);
        preSum[0]=1;
        for(int j=1;j<=t.size();j++) {
            int sum = preSum[0];
            for(int i=1;i<=s.size();i++) {
                if(s[i-1]==t[j-1]) {
                    curSum[i]=sum;
                } else {
                    curSum[i]=0;
                }
                sum+=preSum[i];
            }
            preSum=curSum;
        }
        int ans = 0;
        for(int i=1;i<=s.size();i++) {
            ans += preSum[i];
        }
        return ans;
    }
};