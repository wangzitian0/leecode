# a Topological sort
# no answer if after Topological sort, there are still degree > 0 nodes
# add a list to record the order.
import queue
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        du = [0] * numCourses
        edge = [[] for _ in range(numCourses)]
        for i in range(len(prerequisites)):
            s = prerequisites[i][0]
            t = prerequisites[i][1]
            edge[s].append(t)
            du[t] += 1
        q = queue.Queue()
        order = []
        for i in range(numCourses):
            if du[i] == 0:
                q.put(i)
        while not q.empty():
            cur = q.get()
            order.append(cur)
            for j in range(len(edge[cur])):
                t = edge[cur][j]
                du[t] -= 1
                if du[t] == 0:
                    q.put(t)

        if len(order) != numCourses:
            return []
        return order[::-1]
