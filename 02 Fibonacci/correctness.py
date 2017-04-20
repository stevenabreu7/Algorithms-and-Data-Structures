from fibonacci import *

# result for me was 70

n = 1
while True:
    print(n)
    if (lin_fib(n) != ine_fib(n)):
        break
    n += 1

print("first inaccurate result:",n)
print("inaccurate:", ine_fib(n))
print("  accurate:", lin_fib(n))
