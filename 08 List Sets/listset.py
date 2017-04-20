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

    def getElements(self):
        return self.elements

    def contains(self, x):
        return x in self.elements

    def insert(self, x):
        if not self.contains(x):
            self.elements.append(x)

    def delete(self, x):
        if self.contains(x):
            self.elements.remove(x)

    def __str__(self):
        res = "set: "
        for e in self.elements:
            res += str(e) + " "
        return res

    def __iter__(self):
        for e in self.elements:
            yield e

s = ListSet()
# insert elements
for i in range(10):
    s.insert(i)
# delete some
for i in range(2):
    s.delete(i*2)
# print using iterator
res = "List set: "
for e in s:
    res += str(e) + " "
print(res)
