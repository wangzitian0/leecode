# looks like a bfs, but in fact it was a Dijkstra problem
# due to the i -> j, j could be less than the i. so it could be a loop. bfs don't work
# wa1 for the -1 case, e.g. last 6 cell jump to other place.
#
import queue


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        nn = n * n
        board = board[::-1]
        for i in range(n):
            if i % 2 != 0:
                board[i] = board[i][::-1]
        edge = [[] for _ in range(nn)]
        for i in range(n):
            for j in range(n):
                cur = i * n + j
                for k in range(1, 7):
                    tar = cur + k
                    if tar < nn:
                        ni, nj = tar//n, tar%n
                        if board[ni][nj] == -1:
                            edge[cur].append(tar)
                        else:
                            edge[cur].append(board[ni][nj]-1)
        ans = [nn] * nn
        visited = [False] * nn
        ans[0] = 0
        q = queue.PriorityQueue()
        q.put((ans[0], 0))
        while not q.empty():
            dis, cur = q.get()
            if visited[cur]:
                continue
            visited[cur] = True
            for i in range(len(edge[cur])):
                tar = edge[cur][i]
                if ans[tar] > ans[cur] + 1:
                    ans[tar] = ans[cur] + 1
                    q.put((ans[tar], tar))
        # print(ans)
        if ans[nn-1] == nn:
            return -1
        return ans[nn - 1]
