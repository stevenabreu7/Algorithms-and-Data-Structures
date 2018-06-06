#include <iostream>
#include "Vector.h"

using namespace std;

double defComps[] = {2,3,4};
const int defSize = 3;

Vector::Vector() {
  size = defSize;
  comps = new double[size];
  comps = defComps;
  // cout << "default" << comps[0] << comps[1] << comps[2] << endl;
}

Vector::Vector(const Vector& v) {
  size = v.getSize();
  comps = new double[size];
  comps = v.getComps();
  // cout << "copy" << comps[0] << comps[1] << comps[2] << endl;
}

Vector::Vector(int n, double d[]) : size(n) {
  comps = new double[n];
  comps = d;
  // cout << "full" << comps[0] << comps[1] << comps[2] << endl;
}

Vector::~Vector() {
  // cout << "Bye vector." << endl;
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
  comps = c;
}

void Vector::print() const {
  cout << comps[0] << comps[1] << comps[2] << " ---- ";
  int i;
  string s = "";
  for (i=0;i<size;i++) {
    cout << comps[i] << " ";
  }
  cout << '\n';
}

double Vector::norm() const {
  double sum = 0;
  int i;
  for (i=0;i<size;i++) {
    sum += comps[i] * comps[i];
  }
  return sum;
}

Vector Vector::add(const Vector vc) const {
  double d[size];
  double* vcomps = vc.getComps();
  int i;
  for (i=0;i<size;i++) {
    d[i] = vcomps[i] + comps[i];
  }
  Vector v = Vector(size,d);
  return v;
}

Vector Vector::subtract(const Vector vc) const {
  double d[size];
  double* vcomps = vc.getComps();
  int i;
  for (i=0;i<size;i++) {
    d[i] = vcomps[i] - comps[i];
  }
  Vector v = Vector(size,d);
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
