#include <iostream>
#include "fraction.h"

using namespace std;

int main(void)
{
	Fraction a, b;
  cout << "enter fraction a:\n";
  cin >> a;
  cout << "enter fraction b:\n";
  cin >> b;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
	Fraction great = (a>b) ? a : b;
	cout << "greater: " << great << endl;
	Fraction sum = a+b;
	Fraction dif = a-b;
  cout << "a+b = " << sum << endl;
  cout << "a-b = " << dif << endl;

  return 0;
}
