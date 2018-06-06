/*
  CH08-320142
  a4_p6
  Steven Abreu s.abreu@jacobs-university.de
*/

#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
  double d[] = {5,6,7};
  // cout << "make a, ";
  Vector a(3,d);
  // cout << "make b, ";
  Vector b(a);
  // cout << "make c." << endl;
  Vector c;
  cout << "a: ";
  a.print();
  cout << "b: ";
  b.print();
  cout << "c: ";
  c.print();
  cout << "norm(a): ";
  cout << a.norm() << endl;
  cout << "dot(a,c): ";
  cout << a.dot(c) << endl;
  cout << "sum(a,c): ";
  Vector sum(a.add(c));
  cout << "dif(a,c): ";
  Vector dif(a.subtract(c));
  // cout << '\n';
  return 0;
}
