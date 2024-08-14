
// 19:25 - 20:00
// TLE TLE TLE for 1 hour.
// key point：1->2->3->4 1->5->6->7. can cut lots of search.
//            if (visited[tar] && !reachedEnd[tar]) {
// key point2：
//            if (dis[tar] != deep + 1) {
class Solution {
private:
    unordered_map<string, int> wordToId;
    vector<string> idToWord;
    vector<int> dis;
    vector<bool> visited;
    vector<bool> reachedEnd;
    vector<vector<int>> edge;
    void genAns(int cur, int deep, int endNode, vector<int>& curAns,
                vector<vector<string>>& resp) {
        curAns.push_back(cur);
        if (cur == endNode) {
            vector<string> ansStr;
            for (auto id : curAns) {
                ansStr.push_back(idToWord[id]);
            }
            resp.push_back(ansStr);
            reachedEnd[cur] = true;
        }
        for (int i = 0; i < edge[cur].size(); i++) {
            int tar = edge[cur][i];
            if (visited[tar] && !reachedEnd[tar]) {
                continue;
            }
            if (dis[tar] != deep + 1) {
                continue;
            }
            genAns(tar, deep + 1, endNode, curAns, resp);
            if (reachedEnd[tar]) {
                reachedEnd[cur] = true;
            }
        }
        curAns.pop_back();
        visited[cur] = true;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            wordToId[wordList[i]] = idToWord.size();
            idToWord.push_back(wordList[i]);
        }
        vector<vector<string>> resp;
        if (wordToId.find(endWord) == wordToId.end()) {
            return resp;
        }
        edge.assign(idToWord.size(), vector<int>());
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < i; j++) {
                int s = 0;
                for (int k = 0; k < wordList[i].size(); k++) {
                    if (wordList[i][k] != wordList[j][k]) {
                        s++;
                    }
                }
                if (s == 1) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        priority_queue<pair<int, int>> q;
        dis.assign(idToWord.size(), idToWord.size() + 1);
        visited.assign(idToWord.size(), false);
        dis[wordToId[beginWord]] = 0;
        q.push(make_pair(0, wordToId[beginWord]));
        while (!q.empty()) {
            int curDis = -q.top().first;
            int cur = q.top().second;
            q.pop();
            if (wordToId[endWord] == cur) {
                break;
            }
            if (visited[cur]) {
                continue;
            }
            visited[cur] = true;
            vector<int> newEdge;
            for (int i = 0; i < edge[cur].size(); i++) {
                int tar = edge[cur][i];
                if (dis[tar] > dis[cur] + 1) {
                    dis[tar] = dis[cur] + 1;
                    q.push(make_pair(-dis[tar], tar));
                }
                if (dis[tar] == dis[cur] + 1) {
                    newEdge.push_back(tar);
                }
            }
            edge[cur] = newEdge;
        }
        for (int i = 0; i < idToWord.size(); i++) {
            cout << dis[i] << " ";
        }
        cout << endl;
        vector<int> curAns;
        visited.assign(idToWord.size(), false);
        reachedEnd.assign(idToWord.size(), false);
        genAns(wordToId[beginWord], 0, wordToId[endWord], curAns, resp);
        return resp;
    }
};