from random import randint
from math import log

class MaxHeap:
    def __init__(self):
        # I represent the elements with a list but view them as a binary tree
        self.elements = []

    def __str__(self):
        return self.toString()

    def toString(self):
        res = ""
        for i in range(len(self.elements)):
            res += str(self.elements[i]) + " "
            if i == 0 or i == 2 or i == 6 or i == 14 or i == 30:
                res += "\n"
        return res

    def swapUp(self):
        i = len(self.elements) - 1
        while not i == 0:
            node = self.elements[i]
            parent = self.elements[i // 2]
            if node > parent:
                self.elements[i] = parent
                self.elements[i // 2] = node
            i = i // 2

    def insert(self,x):
        self.elements
        self.elements.append(x)
        self.swapUp()

    def find(self):
        if len(self.elements) > 0:
            return self.elements[0]
        else:
            return None

    def swapDown(self):
        i = 1
        while (2 * i) < len(self.elements):
            lc = 2 * i
            rc = 2 * i + 1
            left = self.elements[lc-1]
            right = self.elements[rc-1]
            node = self.elements[i-1]

            if node >= right and node >= left:
                # no more swapping needed
                break

            if left > right:
                # switch node with left
                self.elements[lc-1] = node
                self.elements[i-1] = left
                i = lc
            else:
                # switch node with right
                self.elements[rc-1] = node
                self.elements[i-1] = right
                i = rc

        # edge case
        if 2*i-1 < len(self.elements):
            left = self.elements[2*i-1]
            node = self.elements[i-1]
            if node < left:
                self.elements[2*i-1] = node
                self.elements[i-1] = left

    def extract(self):
        if len(self.elements) > 0:
            res = self.elements[0]
            self.elements[0] = self.elements[-1]
            self.elements.pop(-1)
            self.swapDown()
            return res
        else:
            return None

class IntPriorityQueue():
    def __init__(self):
        self.heap = MaxHeap()

    def __str__(self):
        return self.heap.toString()

    def enqueue(self,x):
        self.heap.insert(x)

    def dequeue(self):
        return self.heap.extract()

m = IntPriorityQueue()
for i in range(20):
    m.enqueue(randint(0,20))
print(m)
print
for i in range(19):
    print(m.dequeue())
