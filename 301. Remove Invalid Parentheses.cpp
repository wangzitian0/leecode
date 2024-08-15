// just dfs, about 30min.
class Solution {
    string stk;
    string genStr;
    int minRemoval = 25;
    map<string, bool>minAnsSet;
    void dfs(int deep, int removed, const string& s) {
        if (deep == s.size()) {
            if (!stk.empty())
                return;
            if (removed < minRemoval) {
                minRemoval = removed;
                minAnsSet.clear();
            }
            if (removed == minRemoval) {
                minAnsSet[genStr] = true;
            }
            return;
        }
        if (s[deep] == '(') {
            stk.push_back('(');
            genStr.push_back('(');
            dfs(deep + 1, removed, s);
            genStr.pop_back();
            stk.pop_back();
            dfs(deep + 1, removed + 1, s);
        } else if (s[deep] == ')') {
            if(!stk.empty()) {
                stk.pop_back();
                genStr.push_back(')');
                dfs(deep + 1, removed, s);
                genStr.pop_back();
                stk.push_back('(');
            }
            dfs(deep + 1, removed + 1, s);
        } else {
            genStr.push_back(s[deep]);
            dfs(deep + 1, removed, s);
            genStr.pop_back();
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        dfs(0, 0, s);
        vector<string> resp;
        for(auto it: minAnsSet) {
            resp.push_back(it.first);
        }
        return resp;
    }
};