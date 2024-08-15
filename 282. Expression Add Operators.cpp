// 20：45 - 21:45
// just lot of state machine transfer..
// wa for "105"->["1*0+5","10-5"]
class Solution {
    string exp;
    void dfs(int deep, int sum, int prd, long long lastNum, const int target,
             string nums, vector<string>& resp) {
        long long curNum = lastNum * 10 + int(nums[deep] - '0');
        if (deep == nums.size() - 1) {
            if (sum + prd * curNum == target) {
                resp.push_back(exp + nums[deep]);
            }
            return;
        }
        exp.push_back(nums[deep]);
        // no operator
        if (curNum != 0) {
            dfs(deep + 1, sum, prd, curNum, target, nums, resp);
        }
        // +
        exp.push_back('+');
        dfs(deep + 1, sum + prd * curNum, 1, 0, target, nums, resp);
        exp.pop_back();
        // -
        exp.push_back('-');
        dfs(deep + 1, sum + prd * curNum, -1, 0, target, nums, resp);
        exp.pop_back();
        // *
        exp.push_back('*');
        dfs(deep + 1, sum, prd * curNum, 0, target, nums, resp);
        exp.pop_back();
        exp.pop_back();
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        cout<<num<<endl;
        dfs(0, 0, 1, 0, target, num, ans);
        return ans;
    }
};