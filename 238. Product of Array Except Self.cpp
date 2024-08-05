/**

// 18:58 - 19:03
just loop.
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prd;
        prd.push_back(1);
        for (int i = 0; i < nums.size(); i++) {
            prd.push_back(prd[prd.size() - 1] * nums[i]);
        }
        vector<int> ans;
        int prdReversed = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans.push_back(prd[i] * prdReversed);
            prdReversed *= nums[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};