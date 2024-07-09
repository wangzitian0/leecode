/*
9:57 -10:18
WA1: the sort cmp used lot of time.
and wrong index.
*/
class Solution {
public:
    static bool cmp(const std::vector<int>& a, const std::vector<int>& b) {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),cmp);
        int last_start = 0x7FFFFFFF, last_end = -1;
        vector<int>g;
        g.push_back(0x7FFFFFFF);
        g.push_back(0x7FFFFFFF);
        intervals.push_back(g);
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];
            if (last_end>=0&&last_end<cur_start) {
                vector<int>g;
                g.push_back(last_start);
                g.push_back(last_end);
                ans.push_back(g);
                last_start = cur_start;
                last_end = cur_end;
            } else {
                last_start = min(cur_start, last_start);
                last_end = max(cur_end, last_end);
            }
        }
        return ans;
    }
};