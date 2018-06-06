/*
  CH08-320142
  a4_p6
  Steven Abreu s.abreu@jacobs-university.de
*/

#include <iostream>
#include <math.h>
#include "Vector.h"

using namespace std;

double COMPS[] = {2,3,4};
const int SIZE = 3;

Vector::Vector() {
  size = SIZE;
  setComps(COMPS);
  // cout << "hi vector ";
  // print();
}

Vector::Vector(const Vector& v) {
  size = v.getSize();
  setComps(v.getComps());
  // cout << "hi vector ";
  // print();
}

Vector::Vector(int n, double d[]) : size(n) {
  setComps(d);
  // cout << "hi vector ";
  // print();
}

Vector::~Vector() {
  // cout << "bye vector ";
  // print();
  delete[] comps;
}

int Vector::getSize() const {
  return size;
}

double* Vector::getComps() const {
  return comps;
}

void Vector::setSize(int s) {
  size = s;
}

void Vector::setComps(double c[]) {
  int i;
  comps = new double[size];
  for (i=0;i<size;i++) {
    comps[i] = c[i];
  }
}

void printArray(double arr[], int n) {
  int i;
  for (i=0;i<n;i++) {
    cout << arr[i] << " ";
  }
}

void Vector::print() const {
  int i;
  for (i=0;i<size;i++) {
    cout << comps[i] << " ";
  }
  cout << endl;
}

double Vector::norm() const {
  double sum = 0;
  int i;
  for (i=0;i<size;i++) {
    sum += comps[i] * comps[i];
  }
  return sqrt(sum);
}

Vector Vector::add(const Vector vc) const {
  double d[size];
  double* vcomps = vc.getComps();
  int i;
  for (i=0;i<size;i++) {
    d[i] = vcomps[i] + comps[i];
  }
  Vector v = Vector(size,d);
  v.print();
  return v;
}

Vector Vector::subtract(const Vector vc) const {
  double d[size];
  double* vcomps = vc.getComps();
  int i;
  for (i=0;i<size;i++) {
    d[i] = comps[i] - vcomps[i];
  }
  Vector v = Vector(size,d);
  v.print();
  return v;
}

double Vector::dot(const Vector vc) const {
  double sum = 0;
  double* vcomps = vc.getComps();
  int i;
  for (i=0;i<size;i++) {
    sum += vcomps[i] * comps[i];
  }
  return sum;
}
