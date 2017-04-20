class Order():
    def lessOrEqual(self):
        pass

class IntSmaller(Order):
    def lessOrEqual(self, a, b):
        return a <= b

def bubblesort(x, cmp):
    sortd = False
    while not sortd:
        sortd = True
        for i in range(len(x) - 1):
            if cmp.lessOrEqual(x[i+1], x[i]) and not x[i] == x[i+1]:
                sortd = False
                x[i], x[i+1] = x[i+1], x[i]
    return x

print(bubblesort([1,2,3,6,3,5], IntSmaller()))
