/**
10min about
f[i] = min(f[i-curCoin])

 */

 class Solution {
 public:
     const int oo = 0x3f3f3f3f;
     int coinChange(vector<int>& coins, int amount) {
         vector<int> g(amount + 1, oo);
         g[0] = 0;
         for (int i = 1; i <= amount; i++) {
             for (auto coin : coins) {
                 if (i - coin >= 0) {
                     g[i] = min(g[i], g[i - coin] + 1);
                 }
             }
         }
         if (g[amount] == oo)
             return -1;
         return g[amount];
     }
 };