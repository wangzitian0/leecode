/*
10:15 - 10:35

WA 1 local: it was combination, not permutation.
*/
class Solution {
private:
    vector<int>comb;
    void dfs(int level, int frm, int n, int k, vector<vector<int>> &ans){
        if(level==k) {
            ans.push_back(comb);
            return;
        }
        for(int i=frm+1;i<=n;i++) {
            comb.push_back(i);
            dfs(level+1,i,n,k,ans);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        dfs(0,0,n,k,ans);
        return ans;
    }
};