#include <iostream>

class Vector {
  private:
    int size;
    double* comps;
  public:
    Vector();
    Vector(int, double[]);
    Vector(const Vector&);
    ~Vector();
    void print() const;
    int getSize() const;
    double* getComps() const;
    void setSize(int);
    void setComps(double*);
    double norm() const;
    double dot(const Vector) const;
    Vector add(const Vector) const;
    Vector subtract(const Vector) const;
};
