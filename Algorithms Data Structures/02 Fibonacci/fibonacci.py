from time import time
from math import sqrt

def exp_fib(n):
    if n <= 1:
        return n
    else:
        return exp_fib(n-1) + exp_fib(n-2)

def lin_fib(n):
    if n <= 1:
        return n
    else:
        prev = 0
        curr = 1
        for i in range(n):
            nex = curr + prev
            prev = curr
            curr = nex
        return curr

def ine_fib(n):
    phi = (1 + sqrt(5)) / 2
    return int(round(phi**(n+1) / sqrt(5)))
