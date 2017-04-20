// Steven Abreu
// Jacobs University Bremen
// AaDS Fall 2016
// Problem 1.2

import java.math.BigInteger;


class RationalNumber {

  private BigInteger d, e;

  RationalNumber(BigInteger d, BigInteger e) {
    this.d = d;
    // take the absolute value
    if (e.equals(new BigInteger("0"))) {
      System.out.println("WARNING: denominator cannot be zero -> set to 1.");
      this.e = new BigInteger("1");
    } else {
      this.e = e.abs();
    }
  }

  BigInteger getD(){ return d; }

  BigInteger getE(){ return e; }

  void setD(BigInteger i) { d = i; }

  void setE(BigInteger i) { e = i.abs(); }

  Boolean equal(RationalNumber r) {
    if (d.multiply(r.getE()) == e.multiply(r.getD())) {
      return true;
    } else {
      return false;
    }
  }

  RationalNumber getNormal() {
    BigInteger g = gcd(d,e);
    return new RationalNumber(d.divide(g), e.divide(g));
  }

  void makeNormal() {
    BigInteger g = gcd(d,e);
    d = d.divide(g);
    e = e.divide(g);
  }

  // STATIC METHODS
  static BigInteger zero = new BigInteger("0");

  static BigInteger gcd(BigInteger a, BigInteger b) {
    BigInteger r = a.mod(b);
    while (!r.equals(zero)) {
      a = b;
      b = r;
      r = a.mod(b);
    }
    return b;
  }
}

public class Rational {

  public RationalNumber addition(RationalNumber r, RationalNumber s) {
    BigInteger d = r.getD().multiply(s.getE()).add(r.getE().multiply(s.getD()));
    BigInteger e = r.getE().multiply(s.getE());
    return new RationalNumber(d,e);
  }

  public RationalNumber additiveInverse(RationalNumber r) {
    return new RationalNumber(r.getD().multiply(new BigInteger("-1")),r.getE());
  }

  public RationalNumber multiply(RationalNumber r, RationalNumber s) {
    return new RationalNumber(r.getD().multiply(s.getE()),r.getE().multiply(s.getE()));
  }

  public RationalNumber multiplicativeInverse(RationalNumber r) {
    return new RationalNumber(r.getE(), r.getD());
  }

  public static void main(String[] args) {
    BigInteger a = new BigInteger("2");
    BigInteger b = new BigInteger("0");
    new RationalNumber(a,b);
  }
}
