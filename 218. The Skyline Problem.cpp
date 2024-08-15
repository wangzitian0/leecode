// 19:38 - 20:00
// event scan
// use a map to maintaince the high of blocks.
// check the high when the event happend.
// record the ans if the high changed.
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (int i = 0; i < buildings.size(); i++) {
            events.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            events.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        map<int, int> highAndCount;
        sort(events.begin(), events.end());
        vector<vector<int>> ans;
        int preHigh = -1;
        for (int i = 0; i < events.size(); i++) {
            int pos = events[i].first;
            int high = events[i].second;
            if (high < 0) {
                if (highAndCount.find(-high) == highAndCount.end()) {
                    highAndCount[-high] = 0;
                }
                highAndCount[-high]++;
            } else {
                highAndCount[high]--;
                if (highAndCount[high] == 0) {
                    highAndCount.erase(high);
                }
            }
            int curHigh = 0;
            if (!highAndCount.empty()) {
                curHigh = highAndCount.rbegin()->first;
            }
            if (preHigh != curHigh) {
                vector<int>tmp;
                tmp.push_back(pos);
                tmp.push_back(curHigh);
                ans.push_back(tmp);
                preHigh = curHigh;
            }
        }
        return ans;
    }
};