/*
  CH08-320143
  Assignment 1, Problem 5 (bonus)
  Steven Abreu
  s.abreu@jacobs-university.de
*/

#include <iostream>
#include <math.h>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

/*
  Constructors
*/

Matrix::Matrix() {
  rows = 3;
  cols = 3;
  double **d = new double*[rows];
  int i,j;
  for (i = 0; i < rows; i++) {
    d[i] = new double[cols];
    for (j = 0; j < cols; j++) {
      d[i][j] = i*3+j;
    }
  }
  setElements(d);
}

Matrix::Matrix(int r, int c) {
  rows = r;
  cols = c;
  double **d = new double*[rows];
  int i,j;
  for (i = 0; i < rows; i++) {
    d[i] = new double[cols];
    for (j = 0; j < cols; j++) {
      d[i][j] = i*3+j + 10;
    }
  }
  setElements(d);
}

Matrix::Matrix(const Matrix& m) {
  rows = m.getRows();
  cols = m.getCols();
  setElements(m.getElements());
}

Matrix::Matrix(int r, int c, double** d) : rows(r), cols(c) {
  setElements(d);
}

/*
  Destructor
*/

Matrix::~Matrix() {
  int i;
  for (i = 0; i < rows; i++) {
    delete [] entries[i];
  }
  delete [] entries;
}

/*
  Getters
*/

int Matrix::getRows() const {
  return rows;
}

int Matrix::getCols() const {
  return cols;
}

double** Matrix::getElements() const {
  return entries;
}

double Matrix::getElement(int row, int col) const {
  if (row < rows && row >= 0 && col < cols && col >= 0) {
    return entries[row][col];
  } else{
    cout << "Invalid index in Matrix::getElement";
    return 0.0;
  }
}

/*
  Setters
*/

void Matrix::setRows(int r) {
  rows = r;
}

void Matrix::setCols(int c) {
  cols = c;
}

void Matrix::setElement(int row, int col, double val) {
  entries[row][col] = val;
}

void Matrix::setElements(double** d) {
  int r, c;
  entries = new double*[rows];
  for (r = 0; r < rows; r++) {
    entries[r] = new double[cols];
    for (c = 0; c < cols; c++) {
      entries[r][c] = d[r][c];
    }
  }
}

/*
  Operator Overloading
*/

ostream& operator<<(ostream &stream, const Matrix &m) {
  int i,j;
  for (i = 0; i < m.getRows(); i++) {
    for (j = 0; j < m.getCols(); j++) {
      stream << m.getElement(i,j) << " ";
    }
    if (i != m.getRows()-1) {
      stream << endl;
    }
  }
  return stream;
}

istream& operator>>(istream &in, Matrix &m) {
  int rows, cols, i, j;
  in >> rows;
  in >> cols;
  m = Matrix(rows,cols);
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      double temp;
      in >> temp;
      m.setElement(i,j,temp);
    }
  }
  return in;
}

Matrix& Matrix::operator=(const Matrix& m) {
  if (rows > 0 and cols > 0) {
    int i;
    for (i = 0; i < rows; i++) {
      delete [] entries[i];
    }
    delete [] entries;
  }
  rows = m.getRows();
  cols = m.getCols();
  setElements(m.getElements());
  return *this;
}
