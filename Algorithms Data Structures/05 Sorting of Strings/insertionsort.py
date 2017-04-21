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
    for i in range(len(x)):
        current = x[i]
        pos = i
        while pos > 0 and not cmp.leq(x[pos-1], current):
            x[pos] = x[pos-1]
            pos = pos-1
        x[pos] = current
    return x

print(sort(["hey", "name", "steven", "abreu", "this", "that"], Lexicographic()))
