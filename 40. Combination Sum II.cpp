/*
给一个可以重复的数字序列，每个数字仅能出现一次。求所有和为特定数字的子序列。

我测了一组数据：
[0,1,-1]
0
所有数字都是正整数吧，反正题目没说这一点。
我也假定是正整数好了，如果不是改掉 sum<0就退出的边界条件。

1.WA [1,1] 1 输出了[[1],[1]]，使用 erase 的时候一定要记得更新数组大小的临时变量。。。
2.TLE [14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12]
    27
这个地方加上sum<0就过了：
if(sum<0||step==_n)return;

*/
class Solution {
private:
    vector<vector<int>> _ans;
    vector<int> _candidates, _stk;
    map<int, int> _mp;
    int _n;
public:
    void dfs(int step, int sum) {
        if(sum<0||step==_n)return;
        if(sum==0) {
            _ans.push_back(_stk);
            return;
        }
        int cur = _candidates[step];
        if(_mp[cur]>0) {
            _stk.push_back(cur);
            _mp[cur]--;
            dfs(step, sum - cur);
            _mp[cur]++;
            _stk.pop_back();
        }
        dfs(step + 1, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        _candidates = candidates;
        _n = _candidates.size();
        for(int i=0;i<_n;i++) {
            _mp[_candidates[i]]++;
        }
        sort(_candidates.begin(), _candidates.end());
        _candidates.erase(unique(_candidates.begin(), _candidates.end()), _candidates.end());
        reverse(_candidates.begin(), _candidates.end());
        _n = _candidates.size();

        dfs(0, target);
        return _ans;
    }
};