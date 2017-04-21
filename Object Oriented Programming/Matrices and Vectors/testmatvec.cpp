/*
  CH08-320143
  Assignment 1, Problem 5 (bonus)
  Steven Abreu
  s.abreu@jacobs-university.de
*/

/*
  general format of input files:
  matrices:
  rows cols {elements row by row all separated by spaces or new lines}
  vectors:
  dimension {elements separated by spaces or new lines}

  Test contents of in1.txt:
  2 2 1 2 3 4
  -or-
  2 2
  1 2
  3 4

  Test contents of in2.txt:
  3 3 9 8 7 6 5 4 3 2 1
  -or-
  3 3
  9 8 7
  6 5 4
  3 2 1
*/

#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

Vector operator*(const Matrix& m, const Vector& v) {
  if (m.getCols() == v.getSize()) {
    int dim = m.getRows();
    double *d = new double[dim];
    int i,j;
    for (i = 0; i < m.getRows(); i++) {
      d[i] = 0;
      for (j = 0; j < m.getCols(); j++) {
        d[i] += m.getElement(i,j) * v.getElement(j);
      }
    }
    Vector v(dim, d);
    return v;
  } else {
    double d[] = {};
    return Vector(0,d);
  }
}

Vector operator*(const Vector& v, const Matrix& m) {
  if (m.getRows() == v.getSize()) {
    int dim = m.getCols();
    double *d = new double[dim];
    int i,j;
    for (i = 0; i < m.getCols(); i++) {
      d[i] = 0;
      for (j = 0; j < m.getRows(); j++) {
        d[i] += m.getElement(j,i) * v.getElement(j);
      }
    }
    Vector v(dim, d);
    return v;
  } else {
    double d[] = {};
    return Vector(0,d);
  }
}

int main() {

  ifstream in;
  ofstream out;

  /*
    Matrices
  */

  Matrix m,n,o,p;

  // matrix from standard input
  cout << "reading matrix from standard input" << endl;
  cin >> m;
  cout << m << endl;

  // matrix from code
  cout << "coded matrix" << endl;
  n = Matrix(3,4);
  cout << n << endl;

  // matrix from file in1.txt
  cout << "reading matrix from file in1.txt" << endl;
  in.open("in1.txt");
  if (!in.good()) {
    cout << "Error opening file in1.txt" << endl;
    return 1;
  }
  in >> o;
  cout << o << endl;
  in.close();

  // matrix from file in2.txt
  cout << "reading matrix from file in2.txt" << endl;
  in.open("in2.txt");
  if (!in.good()) {
    cout << "Error opening file in1.txt" << endl;
    return 2;
  }
  in >> p;
  cout << p << endl;
  in.close();

  // write matrices to file output1.txt
  out.open("output1.txt");
  if (!out.good()) {
    cout << "Error opening file output1.txt" << endl;
    return 3;
  }
  out << "Matrix m:\n" << m << endl;
  out << "Matrix n:\n" << n << endl;
  out << "Matrix o:\n" << o << endl;
  out << "Matrix p:\n" << p << endl << endl;

  /*
    Vectors
  */

  Vector v,w,x,y,z;

  // vector from standard input
  cout << "reading vector from standard input" << endl;
  cin >> v;
  cout << v << endl;

  // vector from code
  cout << "coded vector" << endl;
  w = Vector();
  cout << w << endl;

  // vector from file in1.txt
  cout << "reading vector from file in1.txt" << endl;
  in.open("in1.txt");
  if (!in.good()) {
    cout << "Error opening file in1.txt" << endl;
    return 1;
  }
  in >> x;
  cout << x << endl;
  in.close();

  // vector from file in2.txt
  cout << "reading vector from file in2.txt" << endl;
  in.open("in2.txt");
  if (!in.good()) {
    cout << "Error opening file in1.txt" << endl;
    return 2;
  }
  in >> y;
  cout << y << endl;
  in.close();

  // write vector to file output1.txt
  out << "Vector v:\n" << v << endl;
  out << "Vector w:\n" << w << endl;
  out << "Vector x:\n" << x << endl;
  out << "Vector y:\n" << y << endl;

  out << "\nMutliplication results:\n";

  out << "m * v = \n" << m * v << endl;
  out << "m * w = \n" << m * w << endl;
  out << "m * x = \n" << m * x << endl;
  out << "m * y = \n" << m * y << endl;

  out << "n * v = \n" << n * v << endl;
  out << "n * w = \n" << n * w << endl;
  out << "n * x = \n" << n * x << endl;
  out << "n * y = \n" << n * y << endl;

  out << "o * v = \n" << o * v << endl;
  out << "o * w = \n" << o * w << endl;
  out << "o * x = \n" << o * x << endl;
  out << "o * y = \n" << o * y << endl;

  out << "p * v = \n" << p * v << endl;
  out << "p * w = \n" << p * w << endl;
  out << "p * x = \n" << p * x << endl;
  out << "p * y = \n" << p * y << endl;

  out << "v * m = \n" << v * m << endl;
  out << "v * n = \n" << v * n << endl;
  out << "v * o = \n" << v * o << endl;
  out << "v * p = \n" << v * p << endl;

  out << "w * m = \n" << w * m << endl;
  out << "w * n = \n" << w * n << endl;
  out << "w * o = \n" << w * o << endl;
  out << "w * p = \n" << w * p << endl;

  out << "x * m = \n" << x * m << endl;
  out << "x * n = \n" << x * n << endl;
  out << "x * o = \n" << x * o << endl;
  out << "x * p = \n" << x * p << endl;

  out << "y * m = \n" << y * m << endl;
  out << "y * n = \n" << y * n << endl;
  out << "y * o = \n" << y * o << endl;
  out << "y * p = \n" << y * p << endl;

  out.close();

  return 0;
}
