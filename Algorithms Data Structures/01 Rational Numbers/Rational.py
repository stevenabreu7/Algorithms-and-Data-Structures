# Steven Abreu
# Jacobs University Bremen
# AaDS Fall 2016
# Problem 1.2

def gcd(a,b):
    r = a % b
    while r != 0:
        a = b
        b = r
        r = a % b
    return b

class Rational:
    def __init__(self,d,e):
        self.d = d
        # take the absolute value
        if e == 0:
            # if input is zero -> do 1 instead
            print("WARNING: denominator cannot be zero -> set to 1.")
            self.e = 1
        else:
            self.e = abs(e)
    def getD(self):
        return self.d
    def getE(self):
        return self.e
    def equal(self,r):
        if self.d * r.getE() == self.e * r.getD():
            return True
        else:
            return False
    def getNormal(self):
        g = gcd(self.d,self.e)
        d1 = self.d/g
        e1 = self.e/g
        return Rational(d1,e1)
    def makeNormal(self):
        g = gcd(self.d,self.e)
        self.d = self.d/g
        self.e = self.e/g
    def __str__(self):
        return str(self.d) + "/" + str(self.e)

def addition(r,s):
    d = r.getD() * s.getE() + r.getE() * s.getD()
    e = r.getE() * s.getE()
    return Rational(d,e)

def additiveInverse(r):
    return Rational(-1*r.getD(),r.getE())

def multiplication(r,s):
    return Rational(r.getD() * s.getD(), r.getE() * s.getE())

def multiplicativeInverse(r):
    return Rational(r.getE(), r.getD())
