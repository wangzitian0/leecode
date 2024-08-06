/**
18:55 - 19:00
just use a stack.
wa1 for negative numbers.

 */


class Solution {
private:
    pair<int, int> getTwoVal(vector<int>& val) {
        int p = val.back();
        val.pop_back();
        int q = val.back();
        val.pop_back();
        return make_pair(q, p);
    }

public:
    int evalRPN(vector<string>& tokens) {
        vector<int> val;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                pair<int, int> valPair = getTwoVal(val);
                val.push_back(valPair.first + valPair.second);
            } else if (tokens[i] == "-") {
                pair<int, int> valPair = getTwoVal(val);
                val.push_back(valPair.first - valPair.second);
            } else if (tokens[i] == "*") {
                pair<int, int> valPair = getTwoVal(val);
                val.push_back(valPair.first * valPair.second);
            } else if (tokens[i] == "/") {
                pair<int, int> valPair = getTwoVal(val);
                val.push_back(valPair.first / valPair.second);
            } else {
                int cur = 0, op = 1;
                for (auto ch : tokens[i]) {
                    if (ch == '-') { // wa 1
                        op = -op;
                    } else {
                        cur = cur * 10 + ch - '0';
                    }
                }
                val.push_back(op*cur);
            }
            cout << val.back() << endl;
        }
        return val[0];
    }
};