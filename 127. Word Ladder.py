# mapping the str to nodes O(len_of_words * number_of_words)
# then generate the graph  O(max_edge = len_of_words * number_of_words * 26)
# the get the min path     O(max_edge * log(nodes number))
import queue
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList.append(beginWord)
        # mapping str to int id
        strToId = {}
        curFlag = 0
        for i in range(len(wordList)):
            if not wordList[i] in strToId:
                strToId[wordList[i]] = curFlag
                curFlag += 1
        if endWord not in wordList:
            return 0
        # generate the edge.
        edge = [[] for _ in range(curFlag)]
        for i in range(len(wordList)):
            curWord = wordList[i]
            curId = strToId[curWord]
            # print(curWord, "------")
            for l in range(len(curWord)):
                for z in string.ascii_lowercase:
                    nextWord = wordList[i][0:l] + z + wordList[i][l + 1 :]
                    if nextWord != curWord and nextWord in strToId:
                        nextId = strToId[nextWord]
                        # print(nextWord)
                        edge[curId].append(nextId)
        print(edge)
        # dijkstra for min distance->ans
        visited = [False] * curFlag
        ans = [0x7FFFFFFF] * curFlag
        ans[strToId[beginWord]] = 0
        q = queue.PriorityQueue()
        q.put((0, strToId[beginWord]))
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

        print(ans)
        if ans[strToId[endWord]] == 0x7FFFFFFF:
            return 0
        return ans[strToId[endWord]] + 1
