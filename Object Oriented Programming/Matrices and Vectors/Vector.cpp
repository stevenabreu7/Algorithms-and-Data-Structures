/*
  CH08-320143
  Assignment 1, Problem 5 (bonus)
  Steven Abreu
  s.abreu@jacobs-university.de
*/

#include <iostream>
#include <math.h>
#include "Vector.h"

using namespace std;

double COMPS[] = {2,3,4};
const int SIZE = 3;

/*
  Constructors
*/

Vector::Vector() {
  size = SIZE;
  setComps(COMPS);
}

Vector::Vector(const Vector& v) {
  size = v.getSize();
  setComps(v.getComps());
}

Vector::Vector(int n, double d[]) : size(n) {
  setComps(d);
}

/*
  Deconstructor
*/

Vector::~Vector() {
  delete[] comps;
}

/*
  Getters
*/

int Vector::getSize() const {
  return size;
}

double* Vector::getComps() const {
  return comps;
}

double Vector::getElement(int index) const {
  if (index < size && index >= 0) {
    return comps[index];
  } else{
    cout << "Invalid index in Vector::getElement" << endl;
    return 0.0;
  }
}

/*
  Setters
*/

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

/*
  Overloaded operators
*/

ostream& operator<<(ostream &stream, const Vector &v) {
  int i;
  for (i = 0; i < v.getSize(); i++) {
    stream << v.getElement(i) << " ";
  }
  return stream;
}

istream& operator>>(istream &in, Vector &v) {
  int size, i;
  in >> size;
  v.setSize(size);
  double *d = new double[size];
  for (i = 0; i < size; i++) {
    in >> d[i];
  }
  v.setComps(d);
  return in;
}

Vector& Vector::operator=(const Vector& v) {
  size = v.getSize();
  setComps(v.getComps());
  return *this;
}

/*
  Vector operations
*/

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
