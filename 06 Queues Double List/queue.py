# Steven Abreu
# Assignment 6.2

from time import time

# class for the single nodes (elements) in the linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

# class definition for the linked list
class DoublyLinkedList():
    def __init__(self):
        self.first = None
        self.last = None

    def __str__(self):
        res = ""
        node = self.first
        while not(node == None):
            res += str(node.data) + " "
            node = node.next
        res += "\nrev: "
        node = self.last
        while not(node == None):
            res += str(node.data) + " "
            node = node.prev
        return res

    def empty(self):
        return self.first == None

    def removeFirst(self):
        if self.first == None:
            return None
        else:
            oldHeadData = self.first.data
            newHead = self.first.next
            if not (newHead == None):
                newHead.prev = None
            self.first = newHead
            return oldHeadData

    def prepend(self, data):
        node = Node(data)
        # check if list is empty
        if self.first == None:
            self.first = node
            self.last = node
        else:
            # this is important to only allow one datatype in the list.
            if type(data) == type(self.first.data):
                node.next = self.first
                self.first.prev = node
                self.first = node
            else:
                print("more than one data type!", type(self.first.data), type(data))

    def append(self, data):
        node = Node(data)
        if self.first == None:
            self.first = node
            self.last = node
        else:
            # this is important to only allow one datatype in the list.
            if type(data) == type(self.first.data):
                self.last.next = node
                node.prev = self.last
                self.last = node
            else:
                print("more than one data type!", type(self.head.data), type(data))

class Queue:
    def __init__(self):
        self.elements = DoublyLinkedList()

    def empty(self):
        return self.elements.empty()

    def enqueue(self, x):
        self.elements.append(x)

    def dequeue(self):
        return self.elements.removeFirst()

    def kill(self):
        res = ""
        res += "elements: "
        while not self.empty():
            res += str(self.dequeue()) + " "
        print(res)

# create new queue (becomes integer queue with the first element added to queue)
q = Queue()
# enqueue some values
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)
# dequeue everything and print
q.kill()

# make sure its constant time
res = ""
for j in [100,1000,10000,100000]:
    start = time()
    for i in range(j):
        q.enqueue(i)
    q.kill()
    end = time()
    res += str((end-start)/j) + "   "
print(res)
