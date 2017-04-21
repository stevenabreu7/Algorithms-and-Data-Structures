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
    sortd = False
    while not sortd:
        sortd = True
        for i in range(len(x) - 1):
            if cmp.leq(x[i+1], x[i]) and not x[i] == x[i+1]:
                sortd = False
                x[i], x[i+1] = x[i+1], x[i]
    return x

print(sort(["hey", "name", "steven", "abreu", "this", "that"], Lexicographic()))
