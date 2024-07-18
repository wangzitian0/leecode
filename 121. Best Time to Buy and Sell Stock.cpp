/**
12:15 - 12:19

just scan the array.

 */

 class Solution {
 public:
     int maxProfit(vector<int>& prices) {
         int lowPrice = 1e6, ans = 0;
         for (auto price : prices) {
             ans = max(ans, price - lowPrice);
             lowPrice = min(lowPrice, price);
         }
         return ans;
     }
 };