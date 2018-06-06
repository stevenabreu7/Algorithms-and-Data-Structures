#include <iostream>
#include <cstdlib>
#include "Complex.h"

using namespace std;

int main(int argc, char** argv) {
  Complex z1, z2, z3, z4;
  double r,i;

  cout << "Enter real(z1): ";
  cin >> r;
  cout << "Enter imaginery(z1): ";
  cin >> i;
  z1 = Complex(r,i);

  cout << "Enter real(z2): ";
  cin >> r;
  cout << "Enter imaginery(z2): ";
  cin >> i;
  z2 = Complex(r,i);

  cout << "Conjugate of z1: ";
  z1.conjugate().print();
  cout << "Sum of z1 and z2: ";
  z1.add(z2).print();
  cout << "Difference z1 - z2: ";
  z1.subtract(z2).print();
  cout << "Product of z1 and z2: ";
  z1.multiply(z2).print();

  cout << "Mic drop." << endl;

  return 0;
}
