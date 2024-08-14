/*
RE1: wrong idea, that travel nodes 1by1.
use a stack to store the node order, and delete the edge 1by1,
if stack.top can not find a next node, push it to ans, and pop from stack.
for the lexical, just make sure visit greater lexical nodes first. after stack reverse it would be min ans.
*/
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> nodes;
        int togo = tickets.size();
        for (int i = 0; i < tickets.size(); i++) {
            nodes.push_back(tickets[i][0]);
            nodes.push_back(tickets[i][1]);
        }
        map<string, int> nodeToId;
        vector<string> idToNode;
        sort(nodes.begin(), nodes.end());
        int n = 0;
        for (auto node : nodes) {
            if (nodeToId.find(node) == nodeToId.end()) {
                idToNode.push_back(node);
                nodeToId[node] = n++;
            }
        }
        vector<vector<int>> edge(n, vector<int>());
        vector<int> balance(n, 0); // degree of out - in

        for (int i = 0; i < tickets.size(); i++) {
            int cur = nodeToId[tickets[i][0]];
            int tar = nodeToId[tickets[i][1]];
            edge[cur].push_back(tar);
            balance[tar]--;
            balance[cur]++;
        }

        for (int i = 0; i < n; i++) {
            sort(edge[i].begin(), edge[i].end());
            reverse(edge[i].begin(), edge[i].end());
        }
        vector<string> ans;
        stack<int>stk;
        stk.push(nodeToId["JFK"]);
        while (!stk.empty()) {
            int cur = stk.top();
            if (edge[cur].size() > 0) {
                int tar = edge[cur].back();
                edge[cur].pop_back();
                stk.push(tar);
            } else {
                stk.pop();
                ans.push_back(idToNode[cur]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};