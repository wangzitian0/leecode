/**
30min about
first want to use O(n) increasedStack, will be wrong for [0,1,0,3,2,3]
maintenance the stack, stack[i] is the min number of length i+1.
waste time on index.

  1   3   5   7
  |           |
 low          up

      1   3   5   7
  |-1 |0
 low  up

  1   3   5   7
              |n-1|n
              low  up
int low = 0, up = increasedStack.size();
// find first increasedStack[up]<num
while (low + 1 < up) {
    int mid = (low + up)/2;
    if (increasedStack[mid]<num) {
        low = mid;
    } else {
        up = mid;
    }
}

int low = -1, up = increasedStack.size();
// find first increasedStack[up]>=num
while (low + 1 < up) {
    int mid = (low + up)/2;
    if (increasedStack[mid]<num) {
        low = mid;
    } else {
        up = mid;
    }
}

 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> increasedStack;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int low = -1, up = increasedStack.size();
            // find first increasedStack[up]>=num
            while (low + 1 < up) {
                int mid = (low + up)/2;
                if (increasedStack[mid]<num) {
                    low = mid;
                } else {
                    up = mid;
                }
            }
            if (up == increasedStack.size()) {
                increasedStack.push_back(num);
            } else {
                increasedStack[up] = num;
            }
        }
        return increasedStack.size();
    }
};