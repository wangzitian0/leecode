# Very interesting problem, think it more than half hour.

# 1 -1 2 0 1 -1 2
# idea0: max(sum[i]-min(sum[j]) | i - j <=n) O(n log n)
# idea1: maintaince a decreased deque->O(n), but it was a middle
# idea2: for no loop case
#  - let f[i]=max(nums[i],f[i-1]+nums[i]) | must choose nums[i], ans = max(f[i])
#  - how to handle loop,
#    - case1: sum[i, j), same as the dp.
#    - sum[0, i] and sum[j,n)
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        ans = nums[0]
        fi = 0
        suffix = 0
        for i in range(len(nums)):
            fi = max(0, fi) + nums[i]
            ans = max(ans, fi)
            suffix += nums[i]
        fiMax = 0
        fi = 0
        for i in range(len(nums)):
            ans = max(ans, fiMax + suffix)
            suffix -= nums[i]
            fi += nums[i]
            fiMax = max(fiMax, fi)
        return ans


