/*
10:53 - 11:20
dfs for ans.

*/
class Solution {
private:
    void dfs(int level, string s, vector<int>curIP,vector<string>&ans) {
        if (level==s.size()) {
            // got the ans;
            if (curIP.size()==4) {
                string ipStr = to_string(curIP[0]);
                for(int i=1;i<4;i++)
                    ipStr += "." + to_string(curIP[i]);
                ans.push_back(ipStr);
            }
            return;
        }
        if (curIP.size()==5) {
            // no ans;
            return;
        }
        int ch = s[level]-'0';
        // add dot/end before ch.
        curIP.push_back(ch);
        dfs(level+1,s,curIP,ans);
        curIP.pop_back();
        // appennd data.
        if(curIP.size()==0||curIP.back()==0) {
            return;
        }
        ch += curIP.back()*10;
        if(ch>255){
            return;
        }
        int tmp = curIP.back();
        curIP.pop_back();
        curIP.push_back(ch);
        dfs(level+1,s,curIP,ans);
        curIP.pop_back();
        curIP.push_back(tmp);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int>curIP;
        dfs(0,s,curIP,ans);
        return ans;
    }
};