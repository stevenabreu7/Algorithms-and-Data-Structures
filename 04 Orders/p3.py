# Steven Abreu
# Assignment 4.3
# March 7th 2017

# abstract class
class Order():
    def lessOrEqual(self):
        pass

# implementation for integer comparison
class IntSmaller(Order):
    def lessOrEqual(self, a, b):
        return a <= b

# implementation for divisibility order
class Divisible(Order):
    def lessOrEqual(self, a, b):
        return b % a == 0

# implementation for lexicographic string comparison
class Lexicographic(Order):
    def lessOrEqual(self, a, b):
        # this uses the built in string comparison in python
        # return a <= b
        #
        # own implementation:
        # if strings are equal, return true
        if a == b:
            return True
        for i in range(len(a)):
            # if out of range in second string -> first one is longer and bigger
            if i >= len(b):
                return False
            # if end of first string but not end of second string and same char
            # then the second string is larger
            if i == len(a) - 1:
                if a[i] == b[i]:
                    if len(b) > len(a):
                        return True
            # if same character, continue comparing next characters
            if ord(a[i]) == ord(b[i]):
                continue
            # if smaller then return true
            elif ord(a[i]) < ord(b[i]):
                return True
            # if bigger then return false
            else:
                return False

# sorted function
def sorted(x, ord):
    for i in range(1,len(x)):
        if ord.lessOrEqual(x[i-1], x[i]):
            continue
        else:
            print(i-1,i)
            return False
    return True


# test cases
i = IntSmaller()
print sorted([1,2,3,4,5], i)

d = Divisible()
print sorted([1,3,9,27,81,162], d)

l = Lexicographic()
print sorted(["a","b","c","d"], l)
print sorted(["Abe", "Abreu", "Abreus", "R"], l)
