/**
randomly get a number, then count.
if its count larger than n/2, is the ans.
O(n)*O(1/2 + 1/4 + 1/8 + .... 1/2^n)


 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        while (true) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                // 1/(i+1) get ->  random/
                if (random() % (i + 1) == 0) {
                    cur = nums[i];
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == cur) {
                    cnt++;
                }
            }
            if (cnt > n / 2) {
                return cur;
            }
        }
    }
};