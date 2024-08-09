# just use a dict to practice python
# heap is better, top k max -> k min smaller heap
# just any structure can key O(log) order.

from sortedcontainers import SortedDict

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        sd = SortedDict()
        sdSize = 0
        for i in range(len(nums)):
            val = nums[i]
            if val not in sd:
                sd[val] = 0
            sd[val] += 1
            sdSize += 1
            if sdSize > k:
                minKey,_ = sd.peekitem(0)
                sd[minKey] -= 1
                if sd[minKey] == 0:
                    del sd[minKey]
                sdSize -= 1
            # print(sdSize, "---")
        minKey,_ = sd.peekitem(0)
        return minKey


