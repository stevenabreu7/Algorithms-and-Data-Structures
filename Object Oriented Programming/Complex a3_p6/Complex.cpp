#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() {
  real = 0;
  imaginery = 0;
}

Complex::Complex(double r, double i) {
  real = r;
  imaginery = i;
}

Complex::~Complex() {
  
}

double Complex::getReal() {
  return real;
}

double Complex::getImaginery() {
  return imaginery;
}

void Complex::setReal(double r) {
  real = r;
}

void Complex::setImaginery(double i) {
  imaginery = i;
}

void Complex::print() {
  if (imaginery > 0) {
    cout << real << " + " << imaginery << "i" << endl;
  } else {
    cout << real << " - " << (-1) * imaginery << "i" << endl;
  }
}

Complex Complex::add(Complex c) {
  double r = real + c.real;
  double i = imaginery + c.imaginery;
  return Complex(r,i);
}

Complex Complex::conjugate() {
  double i = imaginery * (-1);
  return Complex(real,i);
}

Complex Complex::subtract(Complex c) {
  double r = real - c.real;
  double i = imaginery - c.imaginery;
  return Complex(r,i);
}

Complex Complex::multiply(Complex z) {
  double a = real, b = imaginery, c = z.real, d = z.imaginery;
  double r = (a * c) - (b * d);
  double i = (b * c) + (a * d);
  return Complex(r,i);
}
