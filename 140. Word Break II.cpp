// 21:40 - 21:53
class Solution {
private:
    vector<vector<bool>> match;
    int sLen = 0;
    void dfs(int deep, string cur, vector<string>& wordDict,
             vector<string>& resp) {
        if (deep == sLen) {
            resp.push_back(cur);
        }
        if (deep >= sLen) {
            return;
        }
        for (int j = 0; j < wordDict.size(); j++) {
            if (match[deep][j]) {
                if (deep == 0) {
                    dfs(wordDict[j].size(), wordDict[j], wordDict, resp);
                } else {
                    dfs(deep + wordDict[j].size(), cur + " " + wordDict[j],
                        wordDict, resp);
                }
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sLen = s.size();
        for (int i = 0; i < s.size(); i++) {
            match.push_back(vector<bool>(wordDict.size(), true));
            for (int j = 0; j < wordDict.size(); j++) {
                string cur = wordDict[j];
                for (int k = 0; k < cur.size(); k++) {
                    if (i + k > s.size() || s[i + k] != cur[k]) {
                        match[i][j] = false;
                    }
                }
            }
        }
        vector<string> resp;
        dfs(0, "", wordDict, resp);
        return resp;
    }
};