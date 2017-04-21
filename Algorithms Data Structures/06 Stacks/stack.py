# Steven Abreu
# Assignment 6.1

# this is an immutable linked list. we cannot
# modify the value of any of its elements
class ImmutableList():
    def __init__(self, head, tail):
        self.head = head
        self.tail = tail

    def getHead(self):
        return self.head

    def getTail(self):
        return self.tail

class Stack:
    def __init__(self):
        self.elements = ImmutableList(None,None)
        self.length = 0

    def push(self,x):
        # make sure that list only contains one type
        if type(x) == type(self.top()) or self.length == 0:
            self.length += 1
            if self.elements == ImmutableList(None,None):
                self.elements = ImmutableList(x,None)
            else:
                self.elements = ImmutableList(x,self.elements)

    def pop(self):
        x = self.elements.getHead()
        self.elements = self.elements.getTail()
        return x

    def top(self):
        if self.length > 0:
            return self.elements.getHead()
        else:
            return None

test = Stack()
test.push(4)
test.push(5)
test.push(2)
while not test.top() == None:
    print(test.pop())
