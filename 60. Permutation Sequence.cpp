/*
7：45-8:05
9！ * 9 = 3265920
looks good.
*/
class Solution {
private:
    string ans;
    vector<bool>used;
    int count;
    string dfs(int level, int n, int k) {
        if(level==n){
            count++;
            if(count==k) {
                return ans;
            }
            return string();
        }
        for (char ch='1';ch<'1'+n;ch++)
            if (!used[ch-'1']){
                ans.push_back(ch);
                used[ch-'1']=true;
                string str = dfs(level+1,n,k);
                if(str.size())
                    return str;
                used[ch-'1']=false;
                ans.pop_back();
            }
        return string();
    }
public:
    string getPermutation(int n, int k) {
        count = 0;
        used.assign(n,0);
        return dfs(0,n,k);
    }
};