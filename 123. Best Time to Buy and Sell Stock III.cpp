/**
12:35 - 12:49

similar like 121.
But in here need forward scan and then reversed scan.

 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowPrice = 1e6;
        int n = prices.size();
        vector<int> ans(n, 0);
        // ans[i] is the max of [0, i]
        for (int i = 0; i < n; i++) {
            int price = prices[i];
            if (i > 0)
                ans[i] = max(ans[i - 1], price - lowPrice);
            lowPrice = min(lowPrice, price);
        }
        int highPrice = -1, resp = ans[n-1];
        for (int i = n - 1; i >= 0; i--) {
            int price = prices[i];
            if (i + 1 < n && i > 1)
                resp = max(resp, ans[i - 1] + highPrice - price);
            highPrice = max(highPrice, price);
        }
        return resp;
    }
};