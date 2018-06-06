class Vector {
private:
  int size;
  double* comps;
public:
  //constructors
  Vector();
  Vector(int,double[]);
  Vector(const Vector&);
  //destructor
  ~Vector();
  //print
  void print() const;
  //getters
  int getSize() const;
  double * getComps() const;
  //setters
  void setSize(int);
  void setComps(double[]);
  //methods
  double norm() const;
  double dot(const Vector) const;
  Vector add(const Vector) const;
  Vector subtract(const Vector) const;
};
