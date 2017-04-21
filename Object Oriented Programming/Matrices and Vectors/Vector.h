/*
  CH08-320143
  Assignment 1, Problem 5 (bonus)
  Steven Abreu
  s.abreu@jacobs-university.de
*/

#ifndef __VECTOR_H
#define __VECTOR_H

// forward declaration of class for * operator overloading
class Matrix;

class Vector {
private:
  int size;
  double* comps;
public:
  // constructors
  Vector();
  Vector(int, double[]);
  Vector(const Vector&);
  // destructor
  ~Vector();
  // getters
  int getSize() const;
  double getElement(int) const;
  double * getComps() const;
  // setters
  void setSize(int);
  void setComps(double[]);
  // others
  double norm() const;
  double dot(const Vector) const;
  Vector add(const Vector) const;
  Vector subtract(const Vector) const;
  // overloaded operators
  Vector& operator=(const Vector&);
  friend Vector operator*(const Vector&, const Matrix&);
  friend std::ostream& operator<<(std::ostream& stream, const Vector& v);
  friend std::istream& operator>>(std::istream& in, Vector& v);
};

#endif
