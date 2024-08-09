# used 25min to get the correct idea.
# key point is that
#   - if nums[i]<nums[i+1], must have a ans in [i+1, up)
#   - if nums[i]<nums[i+1], must have a ans in [low, i]
# 3 5 1 5 3
# 1 3 4 3 1
# 1 2 3 4 5  3  2
# |low |mid |up
#    1 | 2
#    2 | 1
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        low = 0
        up = len(nums)
        while up - low > 1:
            mid = (low + up) // 2
            if nums[mid - 1] < nums[mid]:
                low = mid
            else:
                up = mid
        return low
