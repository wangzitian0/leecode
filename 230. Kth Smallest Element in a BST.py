# just dfs
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.kth = 0
        self.ans = None
    def dfs(self, cur: Optional[TreeNode], k: int):
        if not cur:
            return
        self.dfs(cur.left, k)
        self.kth += 1
        if self.kth == k:
            self.ans = cur.val
        self.dfs(cur.right, k)
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.dfs(root, k)
        return self.ans
