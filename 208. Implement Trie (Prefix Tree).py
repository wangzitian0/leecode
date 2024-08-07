# just a trie
#


class TrieNode:
    def __init__(self):
        self.nextNode = {}
        self.isEndl = False
    def __str__(self):
        return str(self.nextNode)

class Trie:

    def __init__(self):
        self.trie = TrieNode()

    def insert(self, word: str) -> None:
        curNode = self.trie
        for i in range(len(word)):
            curChar = word[i]
            if curChar not in curNode.nextNode:
                curNode.nextNode[curChar] = TrieNode()
            curNode = curNode.nextNode[curChar]
        curNode.isEndl = True

    def search(self, word: str) -> bool:
        curNode = self.trie
        for i in range(len(word)):
            curChar = word[i]
            if curChar not in curNode.nextNode:
                return False
            curNode = curNode.nextNode[curChar]
        return curNode.isEndl


    def startsWith(self, prefix: str) -> bool:
        curNode = self.trie
        for i in range(len(prefix)):
            curChar = prefix[i]
            if curChar not in curNode.nextNode:
                return False
            curNode = curNode.nextNode[curChar]
        return True



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
