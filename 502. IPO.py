# 10 min write code, 20min debug
# TLE: q.get() will block util the q has element.......
# check the size then pass.
import queue
class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n = len(profits)
        capAndProfit = zip(capital, profits)
        sortedCapAndProfit = sorted(capAndProfit, key=lambda x: (x[0], x[1]))
        print(sortedCapAndProfit)
        nextEvent = 0
        q = queue.PriorityQueue()
        for kk in range(k):
            while nextEvent < n and w >= sortedCapAndProfit[nextEvent][0]:
                event = sortedCapAndProfit[nextEvent]
                q.put((-event[1], event[1]))
                nextEvent += 1
            if not q.empty():
                cur = q.get()
                w += cur[1]
        return w

        