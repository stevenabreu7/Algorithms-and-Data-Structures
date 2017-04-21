/*
  CH08-320143
  Assignment 1, Problem 5 (bonus)
  Steven Abreu
  s.abreu@jacobs-university.de
*/

#ifndef __MATRIX_H
#define __MATRIX_H

// forward declaration of class for * operator overloading
class Vector;

class Matrix {
private:
  int rows, cols;
  double** entries;
public:
  // constructors
  Matrix();
  Matrix(int, int);
  Matrix(int, int, double**);
  Matrix(const Matrix&);
  // destructor
  ~Matrix();
  // getters
  int getRows() const;
  int getCols() const;
  double getElement(int, int) const;
  double** getElements() const;
  // setters
  void setRows(int);
  void setCols(int);
  void setElement(int,int,double);
  void setElements(double**);
  // matrix operations
  double mult(const Matrix) const;
  Matrix add(const Matrix) const;
  Matrix subtract(const Matrix) const;
  // overloaded operators
  Matrix& operator=(const Matrix&);
  friend Vector operator*(const Matrix&, const Vector&);
  friend std::ostream& operator<<(std::ostream& stream, const Matrix& m);
  friend std::istream& operator>>(std::istream& stream, Matrix& m);
};

#endif
