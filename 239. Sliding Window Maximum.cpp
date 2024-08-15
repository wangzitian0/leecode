// use a decrease deque, about 20min.
// when push: pop all e of back that e<cur, then push
// when pop: pop all e's pos < pos - k. Then front is the ans.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> q; // <number, pos>
        vector<int>ans;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            while (!q.empty() && q.back().first <= cur) {
                q.pop_back();
            }
            q.push_back(make_pair(nums[i], i));
            if (i<k-1)continue;
            while (!q.empty() && q.front().second <= i - k) {
                q.pop_front();
            }
            ans.push_back(q.front().first);
        }
        return ans;
    }
};