from random import randint

class Set:
    def __init__(self):
        pass
    def contains(self, x):
        pass
    def insert(self, x):
        pass
    def delete(self, x):
        pass
    def __iter__(self):
        pass

class EmptyIterator:
    def __iter__(self):
        return self
    def __next__(self):
        raise StopIteration

class TreeNode:
    def __init__(self, key, parent = None, left = None, right = None):
        self.key = key
        self.parent = parent
        self.leftChild = left
        self.rightChild = right

    def hasLeftChild(self):
        return not (self.leftChild == None)

    def hasRightChild(self):
        return not (self.rightChild == None)

    def isLeftChild(self):
        return not (self.parent == None) and self.parent.leftChild == self

    def isRightChild(self):
        return not (self.parent == None) and self.parent.rightChild == self

    def isLeaf(self):
        return (self.rightChild == None and self.leftChild == None)

    def hasAnyChildren(self):
        return (self.rightChild == None or self.leftChild == None)

    def hasOneChild(self):
        if self.hasBothChildren():
            return False
        return self.hasAnyChildren()

    def hasBothChildren(self):
        return not (self.rightChild == None or self.leftChild == None)

    def replaceKey(self, key):
        self.key = key

    def __iter__(self):
        if not self == None:
            if self.hasLeftChild():
                for e in self.leftChild:
                    yield e
            yield self.key
            if self.hasRightChild():
                for e in self.rightChild:
                    yield e

class BinarySearchTree(Set):
    def __init__(self):
        self.root = None
        self.size = 0

    def length(self):
        return self.size

    def contains(self, key):
        return not (self._get(key, self.root) == None)

    def insert(self, key):
        if not self.contains(key):
            if self.root:
                self._insert(key, self.root)
            else:
                self.root = TreeNode(key)
                self.size = self.size + 1
        else:
            print("Element is already in BST.")

    def _insert(self, key, current):
        if key < current.key:
            if current.hasLeftChild():
                self._insert(key, current.leftChild)
            else:
                current.leftChild = TreeNode(key, parent = current)
                self.size += 1
        else:
            if current.hasRightChild():
                self._insert(key, current.rightChild)
            else:
                current.rightChild = TreeNode(key, parent = current)
                self.size += 1

    def get(self, key):
        if self.root:
            res = self._get(key, self.root)
            return res
        else:
            return None

    def _get(self, key, current):
        if not current:
            return None
        elif current.key == key:
            return current
        elif key < current.key:
            return self._get(key, current.leftChild)
        else:
            return self._get(key, current.rightChild)

    def delete(self, key):
        node = self._get(key, self.root)
        # node not found
        if node == None:
            raise KeyError
        # remove root
        elif node == self.root and self.size == 1:
            self._deleteRoot()
            self.size -= 1
        # remove node that is leaf
        elif node.isLeaf():
            self._deleteLeaf(node)
            self.size -= 1
        # remove node that has one child
        elif node.hasOneChild():
            self._deleteNodeWithOneChild(node)
            self.size -= 1
        # remove node that has two children
        else:
            self._deleteNodeWithTwoChildren(node)
            self.size -= 1

    def  _deleteRoot(self):
        print("delete root")
        self.root = None

    def _deleteLeaf(self, node):
        print("delete leaf")
        if node.isLeftChild():
            node.parent.leftChild = None
        else:
            node.parent.rightChild = None

    def _deleteNodeWithOneChild(self, node):
        print("delete node with one child")
        # has left child only
        if node.hasLeftChild():
            if node.isLeftChild():
                node.leftChild.parent = node.parent
                node.parent.leftChild = node.leftChild
            elif node.isRightChild():
                node.leftChild.parent = node.parent
                node.parent.rightChild = node.leftChild
            else:
                node.replaceKey(node.leftChild.key)
                node.rightChild = node.leftChild.rightChild
                node.leftChild = node.leftChild.leftChild
                if node.hasLeftChild():
                    node.leftChild.parent = node
                if node.hasRightChild():
                    node.rightChild.parent = node
        # has right child only
        else:
            if node.isLeftChild():
                node.rightChild.parent = node.parent
                node.parent.leftChild = node.rightChild
            elif node.isRightChild():
                node.rightChild.parent = node.parent
                node.parent.rightChild = node.rightChild
            else:
                node.replaceKey(node.rightChild.key)
                node.leftChild = node.rightChild.leftChild
                node.rightChild = node.rightChild.rightChild
                if node.hasLeftChild():
                    node.leftChild.parent = node
                if node.hasRightChild():
                    node.rightChild.parent = node

    def _deleteNodeWithTwoChildren(self, node):
        print("delete node with two children")
        # find minimum in right subtree
        minimum = node.rightChild
        while not minimum.leftChild == None:
            minimum = minimum.leftChild
        # replace node value with minimum value
        node.replaceKey(minimum.key)
        # remove minimum node
        if minimum.isLeaf():
            if minimum.isRightChild():
                minimum.parent.rightChild = None
            elif minimum.isLeftChild():
                minimum.parent.leftChild = None
        else:
            # has a right child (no left children though!)
            minimum.key = minimum.rightChild.key
            minimum.leftChild = minimum.rightChild.leftChild
            minimum.rightChild = minimum.rightChild.rightChild

    def __len__(self):
        return self.size

    def __getitem__(self, key):
        return self.get(key)

    def __contains__(self, key):
        return self.contains(key)

    def __iter__(self):
        if self.root == None:
            return EmptyIterator()
        else:
            return self.root.__iter__()

t = BinarySearchTree()

def test():
    for i in range(15000):
        n = randint(1,500)
        r = randint(0,2)
        if r:
            t.insert(n)
        else:
            try:
                t.delete(n)
            except KeyError:
                print("Key error.")

def loop():
    while True:
        command = input("enter command: ")
        n = int(input("enter integer: "))
        if command == "i":
            print("Inserting", n)
            t.insert(n)
        elif command == "d":
            print("Deleting", n)
            try:
                t.delete(n)
            except KeyError:
                print("Key error. Could not delete.")
        res = "Tree:          "
        for e in t:
            res += str(e) + " - "
        print(res)

choice = input("Would you like to run the test (y/n)?")
if choice == "y":
    print("Starting tests..")
    test()
    t = BinarySearchTree()
    choice = input("Would you like to run the loop (y/n)?")
    if choice == "y":
        print("Starting loop..")
        loop()
else:
    print("Starting loop..")
    loop()
