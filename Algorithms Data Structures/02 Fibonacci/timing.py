from fibonacci import *

# result for me was 36

dif = 0.0
n = 0
res = 0
while True:
    start = time()
    exp_fib(n)
    end = time()
    dif = end - start
    print(n, dif)
    if dif < 10:
        res = n
        n += 1
    else:
        break
print(res, "is the last exponential computation done within 10 seconds.")

answer = input("Would you like an accurate answer for the linear algorithm? (y/n) ")[0]

# with accurate answer, this is my output:
# ....
# 935680 10.005941152572632
# 935648 10.04702115058899
# 935632 10.024570941925049
# 935624 9.970479965209961
# 935628 9.983217000961304
# 935632 9.978601932525635
# 935636 10.029869079589844
# 935632 10.004524946212769
# 935630 9.981276988983154
# 935631 9.997412919998169
# 935632 10.002833127975464
# 935631 is the last linear computation done within 10 seconds.
# with the inaccurate result:
# 886432 is the last linear computation done within 10 seconds.

dif = 0.0
n = 100000
step = 131072
res = 0
while True:
    start = time()
    lin_fib(n)
    end = time()
    dif = end - start
    print(n, dif)
    if dif < 10:
        res = n
        n += step
    else:
        n = n - step
        if answer == 'n':
            break
        if step > 1:
            step = step // 2
        else:
            break

print(res, "is the last linear computation done within 10 seconds.")
