# just dfs, use a stack to record the deep->node
#

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = []

    def dfs(self, cur: Optional[TreeNode], deep: int):
        if not cur:
            return
        if len(self.ans) <= deep:
            self.ans.append(cur.val)
        else:
            self.ans[deep] = cur.val
        self.dfs(cur.left, deep + 1)
        self.dfs(cur.right, deep + 1)

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.dfs(root, 0)
        return self.ans
