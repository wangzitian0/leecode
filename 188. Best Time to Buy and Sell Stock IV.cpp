/**
50 min
WA: use original idea was wrong, greed got max interval.
change it to DP.
f[i][j], 1...i day, transaction j times.
1   3   4   2    5
       k-1  k    i
f[i][j] = max{f[i-1][j], max(f[k-1][j-1] + price[i]-price[k]) | k<i.}
O(n*n*K)
changed it to max(f[k-1][j-1]-price[k]) + price[i]
g[i][j]=max(f[k-1][j-1]-price[k]) | 0<=k<i
g[i-1][j]=max(f[k-1][j-1]-price[k]) | 0<=k<i-1
=max(f[i-2][j-1]-price[i-1], g[i-1][j]);


g[i][j] = max(f[i-2][j-1]-price[i-1], g[i-1][j]); // looks like money you earn - last cost.
f[i][j] = max{f[i-1][j],g[i][j]+price[i])
now it was O(n*k)
then, AC.

 */


class Solution {
public:
     int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
         vector<vector<int>> g(n, vector<int>(k+1, 0));
         vector<vector<int>> f(n, vector<int>(k+1, 0));
         int ans = 0;
         for (int i = 0; i < n; i++) {
             for (int j = 1; j <= k; j++) {
                 if (i >=2) {
                     g[i][j] = max(f[i-2][j-1] - prices[i-1], g[i-1][j]);
                 } else if (i == 1) {
                     g[i][j] = -prices[0];
                 }
                 if (i >= 1) {
                     f[i][j] = max(f[i-1][j], g[i][j] + prices[i]);
                 }
                 ans = max(ans, f[i][j]);
                 cout<<f[i][j]<<" ";
             }
             cout<<endl;
         }
         return ans;
     }
    int maxProfitWrong(int k, vector<int>& prices) { // wrong for [1,2,4,2,5,7,2,4,9,0]
        int n = prices.size();
        vector<int>oneOp;
        int lastBuy = 0;
        for(int i = 0; i < n; i++) {
            if(i == n-1 || prices[i] > prices[i+1]) {
                if (lastBuy < i) {
                    oneOp.push_back(prices[i] - prices[lastBuy]);
                }
                lastBuy = i+1;
            }
        }
        for(auto op : oneOp) {
            cout<<op<<endl;
        }
        sort(oneOp.begin(), oneOp.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i<k && i < oneOp.size(); i++) {
            ans += oneOp[i];
        }
        return ans;
    }
};