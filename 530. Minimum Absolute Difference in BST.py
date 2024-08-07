# use a dict to record the path of root to Node p and q
#

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.nodeToDeep = {}
        self.nodeToDeep2 = {}

    def first_dfs(self, cur: 'TreeNode', p: 'TreeNode', deep: int) -> bool:
        if not cur:
            return False
        self.nodeToDeep[cur] = deep
        if cur == p:
            return True
        elif self.first_dfs(cur.left, p, deep+1):
            return True
        elif self.first_dfs(cur.right, p, deep+1):
            return True
        self.nodeToDeep.pop(cur)
        return False

    def second_dfs(self, cur: 'TreeNode', p: 'TreeNode', deep: int) -> bool:
        if not cur:
            return False
        self.nodeToDeep2[cur] = deep
        if cur == p:
            return True
        elif self.second_dfs(cur.left, p, deep+1):
            return True
        elif self.second_dfs(cur.right, p, deep+1):
            return True
        self.nodeToDeep2.pop(cur)
        return False

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.firstDfs(root, p, 1)
        self.secondDfs(root, q, 1)
        ansDeep = 0
        ans = None
        for k in self.nodeToDeep:
            if k in self.nodeToDeep2 and self.nodeToDeep2[k] > ansDeep:
                ansDeep = self.nodeToDeep2[k]
                ans = k
        return ans
