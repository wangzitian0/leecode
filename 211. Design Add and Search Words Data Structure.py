# just a trie
# most case use the match
# for the '.', travel the subtree. time complexity is a little high.
# don't have other idea.

class TrieNode:
    def __init__(self):
        self.nextNodes = {}
        self.endl = False
import queue
class WordDictionary:

    def __init__(self):
        self.trie = TrieNode()

    def addWord(self, word: str) -> None:
        curNode = self.trie
        for i in range(len(word)):
            ch = word[i]
            if ch not in curNode.nextNodes:
                curNode.nextNodes[ch]=TrieNode()
            curNode = curNode.nextNodes[ch]
        curNode.endl = True


    def search(self, word: str) -> bool:
        q = queue.Queue()
        q.put((0, self.trie))
        while not q.empty():
            i, curNode = q.get()
            if i == len(word):
                if curNode.endl:
                    return True
                else:
                    continue
            ch = word[i]
            if ch != ".":
                if ch not in curNode.nextNodes:
                    continue
                else:
                    q.put((i+1, curNode.nextNodes[ch]))
            elif ch == ".":
                for k in curNode.nextNodes:
                    q.put((i+1, curNode.nextNodes[k]))
        return False



# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)