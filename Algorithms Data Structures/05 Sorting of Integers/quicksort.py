class Order():
    def leq(self):
        pass

class IntSmaller(Order):
    def leq(self, a, b):
        return a <= b

def quicksort(x, cmp):
    return quicksortSublist(x, 0, len(x)-1, cmp)

def quicksortSublist(x, f, l, cmp):
    if f >= l:
        return []
    else:
        pivot = x[l]
        pivotPos = f
        for i in range(f,l):
            if cmp.leq(x[i], pivot):
                x[pivotPos], x[i] = x[i], x[pivotPos]
                pivotPos += 1
        x[pivotPos], x[l] = x[l], x[pivotPos]

        quicksortSublist(x,f,pivotPos-1, cmp)
        quicksortSublist(x,pivotPos+1,l, cmp)
    return x

print(quicksort([1,6,3,67,82,1,4,7,3,2,7], IntSmaller()))
