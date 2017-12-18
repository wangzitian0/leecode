/*
写个搜索就行，dfs 或者 bfs 都行

*/

class Solution {
private:
    vector<string> _ans;
    vector<char> _stk;
    int _n;
    string pp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void dfs(int step, string digits) {
        if(step==_n) {
            string tmp(_stk.begin(), _stk.end());
            if(tmp.size())
                _ans.push_back(tmp);
            return;
        }
        for(int i=pp[digits[step]-'0'].size()-1;i>=0;i--) {
            _stk.push_back(pp[digits[step]-'0'][i]);
            dfs(step+1, digits);
            _stk.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        _n = digits.size();
        dfs(0, digits);
        return _ans;
    }
};
