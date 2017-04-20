
def mergesort(lst):
    if len(lst) < 2:
        return lst
    k = len(lst) // 2
    l = mergesort(lst[0:k])
    r = mergesort(lst[k:len(lst)])
    return merge(l,r)

def merge(a,b):
    arest = a
    brest = b
    res = []
    while len(arest) > 0 or len(brest) > 0:
        takefroma = (len(brest) == 0) or (len(arest) > 0 and arest[0] <= brest[0])
        if takefroma:
            res.append(arest.pop(0))
        else:
            res.append(brest.pop(0))
    return res

print(mergesort([0,6,2,7,4,9,3,62,8,3,85,2]))
