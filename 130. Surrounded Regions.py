# use a dict to record the path of root to Node p and q
#
class Solution:
    def __init__(self):
        self.captured = [0]  # 1 valid 2 invalid
        self.flag = None
        self.dir = [[-1, 0], [1, 0], [0, 1], [0, -1]]

    def dfs(self, p: int, q: int, curFlag: int, board: List[List[str]]):
        if board[p][q] == "X":
            return
        self.flag[p][q] = curFlag
        if p <= 0 or p >= self.n - 1 or q <= 0 or q >= self.m - 1:
            self.captured[curFlag] = 2
        for i in range(4):
            dp = p + self.dir[i][0]
            dq = q + self.dir[i][1]
            if dp < 0 or dp > self.n - 1 or dq < 0 or dq > self.m - 1:
                continue
            if self.flag[dp][dq] != None:
                continue
            self.dfs(dp, dq, curFlag, board)

    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.n = len(board)
        self.m = len(board[0])
        self.flag = [[None] * self.m for _ in range(self.n)]
        curFlag = 0
        for i in range(self.n):
            for j in range(self.m):
                if self.flag[i][j] == None and board[i][j] == "O":
                    curFlag += 1
                    self.captured.append(1)
                    self.dfs(i, j, curFlag, board)
        # print(self.flag)
        # print(self.captured)
        for i in range(self.n):
            for j in range(self.m):
                if self.flag[i][j] != None and self.captured[self.flag[i][j]] == 1:
                    board[i][j] = "X"
