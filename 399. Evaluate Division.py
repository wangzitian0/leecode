# 20min
# idea is that use the floyd algorithm
# wa1, missing a condition, due to change the logic in the coding section
# wa2. precision problem, change the times to log/exp.
class Solution:
    def calcEquation(
            self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        nodeToIndex = {}
        curIndex = 0
        for i in range(len(equations)):
            if equations[i][0] not in nodeToIndex:
                nodeToIndex[equations[i][0]] = curIndex
                curIndex += 1
            if equations[i][1] not in nodeToIndex:
                nodeToIndex[equations[i][1]] = curIndex
                curIndex += 1
        ansMatrix = [[None] * curIndex for _ in range(curIndex)]

        for i in range(len(equations)):
            p = nodeToIndex[equations[i][0]]
            q = nodeToIndex[equations[i][1]]
            ansMatrix[p][q] = math.log(values[i])
            ansMatrix[q][p] = -math.log(values[i])

        for i in range(curIndex):
            ansMatrix[i][i]=0
        for k in range(curIndex):
            for i in range(curIndex):
                for j in range(curIndex):
                    if ansMatrix[i][k] != None and ansMatrix[k][j] != None:
                        ansMatrix[i][j] = ansMatrix[i][k] + ansMatrix[k][j]
        print(ansMatrix)
        ans = []
        for i in range(len(queries)):
            p = nodeToIndex.get(queries[i][0], None)
            q = nodeToIndex.get(queries[i][1], None)
            # wa1 here, missing the ansMatrix[p][q] == None
            if p == None or q == None or ansMatrix[p][q] == None:
                ans.append(-1)
            else:
                ans.append(math.exp(ansMatrix[p][q]))
        return ans
