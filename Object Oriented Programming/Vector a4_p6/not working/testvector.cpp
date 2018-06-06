#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
  double d[] = {1,2,3};
  // cout << "make a" << endl;
  Vector a(3,d);
  // cout << "make b" << endl;
  Vector b(a);
  // cout << "make c" << endl;
  Vector c,v;
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
  v = a.add(c);
  v.print();
  cout << "dif(a,c): ";
  v = a.subtract(c);
  v.print();
  // cout << '\n';
  return 0;
}
