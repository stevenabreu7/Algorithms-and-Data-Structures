# Python version 3
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
    def iterator(self):
        pass

class ListSet(Set):
    def __init__(self):
        self.elements = []

    def contains(self, x):
        return x in self.elements

    def insert(self, x):
        if not self.contains(x):
            self.elements.append(x)
        else:
            print("key error. cannot insert element", x)

    def delete(self, x):
        if self.contains(x):
            self.elements.remove(x)
        else:
            print("key error. cannot delete element", x)

    def __str__(self):
        res = "set: "
        for e in self.elements:
            res += str(e) + " "
        return res

    def __iter__(self):
        for e in self.elements:
            yield e

class HashSet(Set):
    def __init__(self, m):
        self.bucket = [ListSet() for i in range(m)]

    def hash(self, x):
        pass

    def contains(self, x):
        return self.bucket[self.hash(x)].contains(x)

    def insert(self, x):
        self.bucket[self.hash(x)].insert(x)

    def delete(self, x):
        self.bucket[self.hash(x)].delete(x)

    def __str__(self):
        res = ""
        for e in self:
            res += str(e) + " "
        return res

    def __iter__(self):
        for b in self.bucket:
            for e in b:
                yield e

class LastDigitHashSet(HashSet):
    def __init__(self, m):
        super().__init__(10)

    def hash(self, x):
        return x % 10

s = LastDigitHashSet(5)
# inserting elements
for i in range(50):
    s.insert(randint(1,30))
# deleting elements
for i in range(10):
    s.delete(randint(1,30))
# printing elements using iterator
res = "Hash set: "
for e in s:
    res += str(e) + " "
print(res)
