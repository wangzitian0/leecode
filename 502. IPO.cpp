/*
use cpp to write this again.
*/

class Solution {
private:
    struct Node {
        int profit;
        int capital;
        Node(int p, int c) {
            profit = p;
            capital = c;
        };
    };
    struct MinProfit {
        int profit;
        MinProfit(int p) { profit = p; };
        bool operator<(const MinProfit& rhs) const {
            return profit < rhs.profit;
        };
    };
    static int cmp(const Node& p, const Node& q) {
        if (p.capital != q.capital)
            return p.capital < q.capital;
        return q.profit < p.profit;
    }

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<Node> cnp;
        for (int i = 0; i < profits.size(); i++) {
            cnp.emplace_back(profits[i], capital[i]);
        }
        sort(cnp.begin(), cnp.end(), cmp);
        int nextEvent = 0;
        priority_queue<MinProfit> q;
        for (int kk = 0; kk < k; kk++) {
            while (nextEvent < cnp.size() && w >= cnp[nextEvent].capital) {
                MinProfit mp = MinProfit(cnp[nextEvent].profit);
                q.push(mp);
                nextEvent++;
            }
            if (!q.empty()) {
                MinProfit mp = q.top();
                q.pop();
                w += mp.profit;
            }
        }
        return w;
    }
};