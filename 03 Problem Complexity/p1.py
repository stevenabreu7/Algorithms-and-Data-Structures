# find the smallest element in a list of length n

def smallest(lst):
    if len(lst) < 1:
        return None
    m = lst[0]
    for e in lst:
        if e < m:
            m = e
    return e

# worst case complexity is O(n) because the algorithm does one step
# for each element in the list.
# there can be no algorithm that is more efficient because you have
# to check each element at least once.

# --------------------------------------------------------------------------
# --------------------------------------------------------------------------
# --------------------------------------------------------------------------

# find unknown number from 0 to n

# pseudocode:

def guess(x,n):
    print hguess(x,0,n,0)

def mid(a,b):
    return a + abs(a-b) // 2 + (a + b) % 2

def hguess(x,a,b,n):
    # base case 1
    if a == b:
        return n
    # base case 2
    if abs(a-b) == 1:
        n += 1
        if x == a:
            return n
        else:
            return n
    # step case
    n += 1
    # check if in lower half
    if x < mid(a,b):
        return hguess(x,a,mid(a,b),n)
    # in upper half then
    else:
        return hguess(x,mid(a,b),b,n)

# the time complexity of this algorithm is O(n) = log_2(n) because the algorithm
# keeps dividing the range, in which x could possibly be, by two. By repeatingly
# asking whether x is bigger than the mean value, we can get to the solution in
# logarithmic time (average, worst and best-case scenario)
# there is no more efficient algorithm because binary search divides it into
# chunks and every other algorithm would either have to ask more questions
# in the average case and only get "lucky" by guessing correctly. However, the
# worst case complexity will never be lower than this one.

# --------------------------------------------------------------------------
# --------------------------------------------------------------------------
# --------------------------------------------------------------------------

# crack password
def crack(pw,n):
    a = 32
    b = 126
    m = 0
    for i in range(n):
        for j in range(31,126):
            m += 1
            if pw[i] == chr(j):
                print(chr(j))
    print("runs:", m, "- length:", n)

# crack("mYp45Sw0rD!?<>", 9)

# we have to check each character with each of the 95 printable ASCII
# characters. if we decide to accept more than those 95 printable ASCII
# characters, then the algorithm will be more time complex. There can be no
# more efficient algorithm, because we have to check all possibilities.
# however, if we store a lot of default passwords beforehand, we can just
# check all those and we might get lucky and have a time complexity of O(1).
#
# But with this algorithm, we have a worst case time complexity of
# O(n) = 95^n
