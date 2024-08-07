# Very very hard problem as it can not have a certain time complexity.
# used 50 min to think about it.
# try to use a trie to cut down the number  -> TLE
# try to remove the matched string from trie  -> WA
#
# if gen in self.ans:
#     remove.     this version would have problem with 'oa', 'oaa'
# remove op should only happen at the moment ans[gen] from False to True, as the gen is the prefix.
# if gen in self.ans and not self.ans[gen]:
#     remove.     this version



# copy from trie
class TrieNode:
    def __init__(self):
        self.nextNode = {}
        self.count = 0


class Trie:

    def __init__(self):
        self.trie = TrieNode()

    def insert(self, word: str) -> None:
        curNode = self.trie
        for i in range(len(word)):
            curChar = word[i]
            if curChar not in curNode.nextNode:
                curNode.nextNode[curChar] = TrieNode()
            curNode.count += 1
            curNode = curNode.nextNode[curChar]

    def startsWith(self, prefix: str) -> bool:
        curNode = self.trie
        for i in range(len(prefix)):
            curChar = prefix[i]
            if curChar not in curNode.nextNode:
                return False
            curNode = curNode.nextNode[curChar]
        return True

    def remove(self, word: str):
        curNode = self.trie
        for i in range(len(word)):
            curChar = word[i]
            nextNode = curNode.nextNode[curChar]
            curNode.count -= 1
            if curNode.count == 0:
                curNode.nextNode = {}
            curNode = nextNode


class Solution:
    def __init__(self):
        self.dir = [[-1, 0], [1, 0], [0, 1], [0, -1]]
        self.ans = {}

    def dfs(self, p: int, q: int, gen: str):
        self.visiting[p][q] = True
        if gen in self.ans and not self.ans[gen]:
            self.ans[gen] = True
            self.trie.remove(gen)
        for i in range(4):
            dp = p + self.dir[i][0]
            dq = q + self.dir[i][1]
            if dp < 0 or dp >= self.n or dq < 0 or dq >= self.m:
                continue
            if self.visiting[dp][dq]:
                continue
            newStr = gen + self.board[dp][dq]
            if not self.trie.startsWith(newStr):
                continue
            self.dfs(dp, dq, newStr)
        self.visiting[p][q] = False

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.n = len(board)
        self.m = len(board[0])
        self.visiting = [[False] * self.m for _ in range(self.n)]
        self.trie = Trie()
        self.board = board
        for i in range(len(words)):
            self.trie.insert(words[i])
            self.ans[words[i]] = False
        for i in range(self.n):
            for j in range(self.m):
                if self.trie.startsWith(board[i][j]):
                    self.dfs(i, j, board[i][j])
        resp = []
        for i in range(len(words)):
            if words[i] in self.ans and self.ans[words[i]]:
                resp.append(words[i])
        return resp
