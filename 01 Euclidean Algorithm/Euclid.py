# Steven Abreu
# Jacobs University Bremen
# AaDS Fall 2016
# Problem 1.1

# wikipedia:
# the built-in int (3.x) / long (2.x) integer type is of arbitrary precision.
# since I am running python 3, int is sufficient for this task

# from notes
def gcd(a,b):
    while a != b:
        if a < b:
            b = b-a
        else:
            a = a - b
    return a

# more efficient
def gcd1(a,b):
    r = a % b
    while r != 0:
        a = b
        b = r
        r = a % b
    return b

# tests
print(6 == gcd(270,192))
print(6 == gcd(54,24));
print(2 == gcd(382,190))
print(4 == gcd(831737489137489172,1765341241289412784))
