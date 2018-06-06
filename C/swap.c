/*
  JTSK-320111
  a4_p7.c
  Steven Abreu
  s.abreu@jacobs-university.de
*/

#include <stdio.h>

double sum(double a, double b);
void sumbyref(double a, double b, double *s);
void swapbyref(double *a, double *b);
int main() {
    double a, b, s;
    printf("Enter first double: ");
    scanf("%lf", &a);
    printf("Enter second double: ");
    scanf("%lf", &b);

    printf("Result of first function: %lf\n", sum(a, b));
    sumbyref(a, b, &s);
    printf("Result of second function: %lf\n", s);
    printf("Before swap: a=%lf and b=%lf\n", a, b);
    swapbyref(&a, &b);
    printf("After swap: a=%lf and b=%lf\n", a, b);

    return 0;
}
double sum(double a, double b) {
    return (a + b);
}
void sumbyref(double a, double b, double *s) {
    *s = a + b;
}
void swapbyref(double *a, double *b) {
    double temporaryA = *a;
    double temporaryB = *b;
    *b = temporaryA;
    *a = temporaryB;
}
