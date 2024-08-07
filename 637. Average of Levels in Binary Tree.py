# just dfs and record sum and count
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum_and_count = [[] for i in range(2)]
    def dfs(self, cur: Optional[TreeNode], deep):
        if not cur:
            return
        if len(self.sum_and_count[0]) <= deep:
            self.sum_and_count[0].append(0)
            self.sum_and_count[1].append(0)
        self.sum_and_count[0][deep] += cur.val
        self.sum_and_count[1][deep] += 1
        self.dfs(cur.left, deep + 1)
        self.dfs(cur.right, deep + 1)

    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        self.dfs(root, 0)
        ans = []
        for i in range(len(self.sum_and_count[0])):
            ans.append(self.sum_and_count[0][i]/self.sum_and_count[1][i])
        return ans
