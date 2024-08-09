# used 25min to get the correct idea.
# key point is that
#   - if nums[low]<nums[i+1], must have a ans in [i+1, up)
#   - if nums[low]<nums[i+1], must have a ans in [low, i]

# |low |mid |up
#    3 | 1
#    1 | 3

class Solution:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        up = len(nums)
        while up - low > 1:
            mid = (up + low) // 2
            if nums[low] < nums[mid]:
                low = mid
            else:
                up = mid
        return nums[up%len(nums)]
