class Order():
    def leq(self):
        pass

class IntSmaller(Order):
    def leq(self, a, b):
        return a <= b

def insertionSort(x, cmp):
    for i in range(len(x)):
        current = x[i]
        pos = i
        while pos > 0 and not cmp.leq(x[pos-1], current):
            x[pos] = x[pos-1]
            pos = pos-1
        x[pos] = current
    return x

print(insertionSort([1,2,5,12,5,3,2,66,34], IntSmaller()))
