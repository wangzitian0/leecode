# build a 4-child tree like geohash
#

"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""


class Solution:
    def _construct(self, x, y, d) -> "Node":
        if d <= 1:
            return Node(self.grid[x][y], True, None, None, None, None)
        mid = d // 2
        tlNode = self._construct(x, y, mid)
        trNode = self._construct(x, y + mid, mid)
        blNode = self._construct(x + mid, y, mid)
        brNode = self._construct(x + mid, y + mid, mid)
        val = tlNode.val
        isLeaf = False
        if tlNode.isLeaf and trNode.isLeaf and blNode.isLeaf and brNode.isLeaf:
            if val == trNode.val and val == brNode.val and val == blNode.val:
                isLeaf = True
                tlNode, trNode, blNode, brNode = None, None, None, None
        # print(x, y, d, val, isLeaf)
        return Node(val, isLeaf, tlNode, trNode, blNode, brNode)

    def construct(self, grid: List[List[int]]) -> "Node":
        self.grid = grid
        n = len(grid)
        return self._construct(0, 0, n)
