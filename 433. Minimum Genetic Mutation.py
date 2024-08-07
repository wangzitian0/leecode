# floyd.
# wa1 for the case that bank=[], it should output -1.
class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        bank.append(startGene)
        n = len(bank)
        t = -1
        for i in range(n):
            if bank[i] == endGene:
                t = i
        if t == -1:
            return -1
        edge = [[0x7fffffff]*n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                diff = 0
                for k in range(8):
                    if bank[i][k] != bank[j][k]:
                        diff += 1
                if diff<=1:
                    edge[i][j]=diff

        for i in range(n):
            edge[i][i] = 0
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    edge[i][j] = min(edge[i][j], edge[i][k]+edge[k][j])
        if edge[n-1][t] == 0x7fffffff:
            return -1
        return edge[n-1][t]

