# a Topological sort
# no answer if after Topological sort, there are still degree > 0 nodes
import queue
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        du = [0] * numCourses
        edge = [[] for _ in range(numCourses)]
        for i in range(len(prerequisites)):
            s = prerequisites[i][0]
            t = prerequisites[i][1]
            edge[s].append(t)
            du[t] += 1
        q = queue.Queue()
        for i in range(numCourses):
            if du[i] == 0:
                q.put(i)
        while not q.empty():
            cur = q.get()
            for j in range(len(edge[cur])):
                t = edge[cur][j]
                du[t] -= 1
                if du[t] == 0:
                    q.put(t)

        for i in range(numCourses):
            if du[i] != 0:
                return False
        return True
