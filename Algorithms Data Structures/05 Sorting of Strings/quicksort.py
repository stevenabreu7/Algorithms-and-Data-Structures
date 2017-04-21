class Order():
    def leq(self):
        pass

class IntSmaller(Order):
    def leq(self, a, b):
        return a <= b

class Lexicographic(Order):
    def leq(self, a, b):
        if a == b:
            return True
        for i in range(len(a)):
            if i >= len(b):
                return False
            if i == len(a) - 1:
                if a[i] == b[i]:
                    if len(b) > len(a):
                        return True
            if ord(a[i]) == ord(b[i]):
                continue
            elif ord(a[i]) < ord(b[i]):
                return True
            else:
                return False

def sort(x, cmp):
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

print(sort(["hey", "name", "steven", "abreu", "this", "that"], Lexicographic()))
