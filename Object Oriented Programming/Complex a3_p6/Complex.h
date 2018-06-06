using namespace std;

class Complex
{
  private:
    double real;
    double imaginery;
  public:
    double getReal();
    double getImaginery();
    void setReal(double);
    void setImaginery(double);
    void print();
    ~Complex();
    Complex();
    Complex(double, double);
    Complex conjugate();
    Complex add(Complex);
    Complex subtract(Complex);
    Complex multiply(Complex);
};
