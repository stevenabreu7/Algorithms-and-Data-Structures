# Steven Abreu
# Assignment 6.4

class BufferOverflow(Exception):
    pass

class BufferUnderflow(Exception):
    pass

class Buffer:
    def __init__(self, n):
        self.elements = [None for i in range(n)]
        self.size = n
        self.begin = 0
        self.capacity = 0

    def __str__(self):
        res = "Data Structure: "
        for i in range(self.size):
            res += str(self.elements[i]) + " "
        res += "\nStarting right: "
        i = self.begin
        for j in range(self.size):
            res += str(self.elements[(i+j) % self.size]) + " "
        return res

    def enqueue(self, x):
        if self.capacity >= self.size:
            raise BufferOverflow()
        self.elements[(self.begin + self.capacity) % self.size] = x
        print(self.elements[(self.begin + self.capacity) % self.size])
        self.capacity += 1

    def dequeue(self):
        if self.capacity == 0:
            raise BufferUnderflow()
        temp = self.elements[self.begin % self.size]
        self.begin += 1
        self.capacity -= 1
        return temp

    def kill(self):
        res = ""
        while self.capacity > 0:
            res += str(self.dequeue()) + " "
        print(res)

b = Buffer(10)
# enqueue and dequeue values
for i in range(1,9):
    b.enqueue(i)
for i in range(5):
    b.dequeue()
for i in range(9,16):
    b.enqueue(i)
b.dequeue()
b.enqueue(16)
# show how buffer list looks and how it is meant to be
print(b)
# dequeue all and print
b.kill()
