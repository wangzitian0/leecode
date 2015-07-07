class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        dic = {}
        for i in range(0,len(nums)):
            p = dic.get(target-nums[i])
            if p:
                return [p,i+1]
            dic[nums[i]]=i+1


so = Solution()
testnums = [2,7,11,15]
testtarget = 9

print so.twoSum(testnums,testtarget)

