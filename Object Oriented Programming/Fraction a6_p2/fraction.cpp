#include <iostream>
#include "fraction.h"

Fraction::Fraction()
{
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d)
{
	int tmp_gcd = gcd(n, d);

	num = n / tmp_gcd;
	den = d / tmp_gcd;
}

//making it recursive!
int Fraction::gcd(int a, int b)
{
	if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int Fraction::lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

void Fraction::print()
{
	std::cout << num << "/" << den << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Fraction& f) {
  stream << f.num << "/" << f.den;
  return stream;
}

std::istream& operator >>(std::istream& in, Fraction &f) {
  std::cout << "numerator: ";
  in >> f.num;
  std::cout << "denominator: ";
  in >> f.den;
  if (f.den == 0) {
    //invalid
    f.den = 1;
    std::cout << "invalid input. changed denominator to 1." << std::endl;
  }
  int tgcd = f.gcd(f.num, f.den);
  f.num = f.num / tgcd;
  f.den = f.den / tgcd;
  return in;
}

Fraction Fraction::operator*(Fraction f) {
  Fraction a(num * f.num, den * f.den);
  return a;
}

Fraction Fraction::operator/(Fraction f) {
  Fraction a(num * f.den, den * f.num);
  return a;
}

Fraction Fraction::operator+(Fraction f) {
	int a = num, b = den, c = f.num, d = f.den;
	Fraction g((a * lcm(b,d)) / b + (c * lcm(b,d)) / d, lcm(b,d));
	return g;
}

Fraction Fraction::operator-(Fraction f) {
	int a = num, b = den, c = f.num, d = f.den;
	Fraction g((a * lcm(b,d)) / b - (c * lcm(b,d)) / d, lcm(b,d));
	return g;
}

Fraction& Fraction::operator=(const Fraction& f) {
	num = f.num;
	den = f.den;
	return *this;
}

bool Fraction::operator>(Fraction f) {
	return ((num / den) > (f.num / f.den));
}

bool Fraction::operator<(Fraction f) {
	return ((num / den) < (f.num / f.den));
}
