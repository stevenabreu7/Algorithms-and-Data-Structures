
class Node:
    def __init__(self, d, ch):
        self.data = d
        self.children = ch

    def __str__(self):
        return str(self.data)

    def getData(self):
        return self.data

    def getChildren(self):
        return self.children

class Tree:
    def __init__(self,r):
        self.root = r

    def getRoot(self):
        return self.root

class IteratorDFS:
    def __init__(self, t):
        self.tree = t
        self.stack = []
        self.stack.append(self.tree.getRoot())

    def hasNext(self):
        return not len(self.stack) == 0

    def getNext(self):
        if not self.hasNext():
            print("END")
            return None
        res = self.stack.pop()
        childs = reversed(res.getChildren())
        for c in childs:
            self.stack.append(c)
        return res

leaves = []
for i in range(10):
    leaves.append(Node(i,[]))
nodes = []
for i in range(5):
    nodes.append(Node(i+10, [leaves[2*i], leaves[2*i+1]]))
nodes1 = [Node(15,[nodes[0], nodes[1], nodes[2]]), Node(16,[nodes[3], nodes[4]])]
root = Node(17,nodes1)
tree = Tree(root)
it = IteratorDFS(tree)
while it.hasNext():
    print(it.getNext())
