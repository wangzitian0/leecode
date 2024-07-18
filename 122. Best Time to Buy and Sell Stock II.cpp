/**
12:19 - 12:32

for the case
1 4,  got 3
1 2 3 4, got 3
1 3 2 4, got 4
easy to find that as long as price[t+1] < price[t], then you can sell at t, buy at t+1.
then, for previous case, you can same day sell and buy.
ans is sum(delta = prices[i + 1] - prices[i]) if delta > 0
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int hold = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (i == prices.size() - 1 || prices[i] > prices[i + 1]) {
            } else {
                ans += prices[i + 1] - prices[i];
            }
        }
        return ans;
    }
};