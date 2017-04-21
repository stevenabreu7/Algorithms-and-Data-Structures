# Steven Abreu
# Assignment 6.3

class ImmutableLinkedList():
    def __init__(self, head, tail):
        self.head = head
        self.tail = tail

    def getHead(self):
        return self.head

    def getTail(self):
        return self.tail

    def reverse(self):
        rev = ImmutableLinkedList(self.head, None)
        a = self.tail
        while not a == None:
            rev = ImmutableLinkedList(a.getHead(), rev)
            a = a.getTail()
        return rev

    def toString(self):
        res = ""
        c = 0
        a = ImmutableLinkedList(self.head, self.tail)
        while not a == None:
            c+=1
            res += str(a.getHead()) + " "
            a = a.getTail()
        return res

    def __str__(self):
        return self.toString()

class Queue:
    def __init__(self):
        self.inl = ImmutableLinkedList(None,None)
        self.outl = ImmutableLinkedList(None,None)

    def __str__(self):
        return self.inl.toString()

    def empty(self):
        return (self.inl.getHead() == None)

    def enqueue(self,x):
        if (not x == None):
            if self.empty():
                self.inl = ImmutableLinkedList(x,None)
            elif type(x) == type(self.inl.getHead()):
                self.inl = ImmutableLinkedList(x,self.inl)

    def dequeue(self):
        if self.empty():
            print("Queue Underflow")
            return None
        else:
            self.outl = self.inl.reverse()
            res = self.outl.getHead()
            self.outl = self.outl.getTail()
            if self.outl == None:
                self.inl = ImmutableLinkedList(None,None)
            else:
                self.inl = self.outl.reverse()
            self.outl = ImmutableLinkedList(None,None)
            return res

    def kill(self):
        res = ""
        while True:
            if self.inl == None:
                break
            if self.empty():
                break
            res += str(self.dequeue()) + " "
        print(res)

# l = ImmutableLinkedList(1,ImmutableLinkedList(2,ImmutableLinkedList(3,None)))
# r = ImmutableLinkedList(None,None)
# print(l)
# print(l.getHead())
# print(l.getTail())
# print(l.reverse())

# q = Queue()

# print("enqueue 1")
# q.enqueue(1)
# print(q)
# print("enqueue 2")
# q.enqueue(2)
# print(q)
# print("enqueue 3")
# q.enqueue(3)
# print(q)

# print("kill")
# q.kill()

# print("enqueue 1")
# q.enqueue(1)
# print(q)
# print("enqueue 2")
# q.enqueue(2)
# print(q)
# print("enqueue 3")
# q.enqueue(3)
# print(q)

# print("dequeue",q.dequeue())
# print(q)
# print("dequeue",q.dequeue())
# print(q)
