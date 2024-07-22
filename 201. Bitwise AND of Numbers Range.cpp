/**
12 min
l += lowbit(l);
you can get the lowbit's new 0, after the and operation, ans will be also 0.
used long long for easier range.
 */

 class Solution {
 public:
     inline long long lowbit(long long p) {
         return p & (-p);
     }
     int rangeBitwiseAnd(int left, int right) {
         int ans = 0x7FFFFFFF;
         long long l = left;
         while (l <= right) {
             ans &= l;
             l += max(1LL, lowbit(l));
             cout<<l<<endl;
         }
         return ans;
     }
 };