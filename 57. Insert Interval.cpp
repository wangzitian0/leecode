/*
10:20 - 10:41
WA x 3
Very simple but did not get right index.
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        bool pushed = false;
        for(int i=0;i<intervals.size();i++) {
            if(intervals[i][1]<newInterval[0])
                ans.push_back(intervals[i]);
            else if (newInterval[1]<intervals[i][0]){
                if(!pushed){
                    ans.push_back(newInterval);
                    pushed = true;
                }
                ans.push_back(intervals[i]);
            }
            else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        if(!pushed)ans.push_back(newInterval);
        return ans;
    }
};