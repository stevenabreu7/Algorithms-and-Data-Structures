/*
 JTSK-320111
 a6_p7.c
 Steven Abreu
 s.abreu@jacobs-university.de
 */

#include <stdio.h>

int gcd(int a, int b);
int main() {
    int a,b;

    printf("Enter number a: ");
    scanf("%d", &a);
    printf("Enter number b: ");
    scanf("%d", &b);

    printf("GCD is %d.\n", gcd(a, b));

    return 0;
}

int gcd(int a, int b) {
    //this is basically just the coded version of the algorithm described in the assignment
    //so you can see this as the translation into code
    if (a % b == 0) {
        return b;
    } else if (b % a == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}
