class Order():
    def leq(self):
        pass

class IntSmaller(Order):
    def leq(self, a, b):
        return a <= b

def head(l):
    if len(l) >= 1:
        return l[0]
    else:
        print("error, list doesnt have a head")
        return None

def merge(x, y, cmp):
    x_rest = x
    y_rest = y
    res = []
    while not (len(x_rest) == 0) or not (len(y_rest) == 0):
        take_from_x = (len(y_rest) == 0) or ((not len(x_rest) == 0) and cmp.leq(head(x_rest), head(y_rest)))
        if take_from_x:
            # appending takes linear time -> quadratic in total
            res.append(x_rest.pop(0))
        else:
            res.append(y_rest.pop(0))
    return res

def mergesort(x, cmp):
    n = len(x)
    if n < 2:
        return x
    else:
        k = n // 2
        l = mergesort(x[0:k], cmp)
        r = mergesort(x[k:n], cmp)
        return merge(l,r, cmp)

print(mergesort([1,7,3,1,8,2,55,9,2], IntSmaller()))
