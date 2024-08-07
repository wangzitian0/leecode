# just a bfs
#
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
import queue

class Solution:
    def softCopy(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return None
        return Node(node.val, [])

    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return None
        nodeToNode = {}
        q = queue.Queue()
        q.put(node)
        nodeToNode[node] = self.softCopy(node)
        while not q.empty():
            curNode = q.get()
            newNode = nodeToNode[curNode]
            print("--------", curNode.val)
            for i in range(len(curNode.neighbors)):
                curNeighbor = curNode.neighbors[i]
                if curNeighbor not in nodeToNode:
                    nodeToNode[curNeighbor] = self.softCopy(curNeighbor)
                    q.put(curNeighbor)
                newNode.neighbors.append(nodeToNode[curNeighbor])
        return nodeToNode[node]
