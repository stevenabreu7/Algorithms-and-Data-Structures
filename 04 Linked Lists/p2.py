# Steven Abreu
# Assignment 4.2
# March 7th 2017

# class for the single nodes (elements) in the linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# class definition for the linked list
class LinkedList():
    def __init__(self):
        self.head = None

    def __str__(self):
        res = ""
        node = self.head
        while not(node == None):
            res += str(node.data) + " "
            node = node.next
        return res

    # prepend an element to the linked list (at the beginning)
    def prepend(self, data):
        node = Node(data)
        if self.head == None:
            self.head = node
        else:
            # this is important to only allow one datatype in the list.
            if not type(data) == type(self.head.data):
                print("more than one data type!", type(self.head.data), type(data))
                return None
            node.next = self.head
            self.head = node

    # append an element to the linked list (at the end)
    def append(self, data):
        node = Node(data)
        if self.head == None:
            self.head = node
        else:
            # this is important to only allow one datatype in the list.
            if not type(data) == type(self.head.data):
                print("more than one data type!", type(self.head.data), type(data))
                return None
            end = self.head
            while not (end.next == None):
                end = end.next
            end.next = node

    # add list to this linked list
    def add(self, lst):
        for e in lst:
            self.append(e)

    # get element at index i
    def get(self,i):
        if i >= self.length():
            return None
        else:
            node = self.head
            for j in range(i):
                node = node.next
            return node.data

    # get length of the linked list
    def length(self):
        n = 0
        node = self.head
        while not(node == None):
            node = node.next
            n += 1
        return n

# reverses the list and returns it as a new list
def reverse(llst):
    rev = LinkedList()
    for i in range(llst.length()):
        rev.prepend(llst.get(i))
    return rev

# this concats b to a
def concat(a,b):
    i = 0
    while i < b.length():
        a.append(b.get(i))
        i += 1
    return a

print("l")
l = LinkedList()
print("b")
b = LinkedList()

l.add([1,2,3,4])
b.add(["v",8,8])

print("l =", l)
print("b =", b)

b = LinkedList()
b.add([9,9,9])

print("b =", b)

print("concat(l,b) =", concat(l,b))

print("reverse(l) =", reverse(l))
