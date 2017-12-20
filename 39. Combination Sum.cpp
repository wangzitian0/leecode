/*
leetcode 比较有意思的一点是但凡有 i ii iii 这种标号的题目，先做大的，小的自然而然就过了。。
但是这个题目不是。。。。瞎交 WA 了一发，这个题目的数字是可以重复的。

*/


class Solution {
private:
    vector<vector<int>> _ans;
    vector<int> _candidates, _stk;
    int _n;
public:
    void dfs(int step, int sum) {
        if(sum<0||step==_n)return;
        if(sum==0) {
            _ans.push_back(_stk);
            return;
        }
        int cur = _candidates[step];
        _stk.push_back(cur);
        dfs(step, sum - cur);
        _stk.pop_back();
        dfs(step + 1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        _candidates = candidates;
        _n = _candidates.size();
        sort(_candidates.begin(), _candidates.end());
        reverse(_candidates.begin(), _candidates.end());

        dfs(0, target);
        return _ans;
    }
};