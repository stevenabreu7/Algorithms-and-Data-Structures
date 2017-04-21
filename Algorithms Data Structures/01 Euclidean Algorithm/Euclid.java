// Steven Abreu
// Jacobs University Bremen
// AaDS Fall 2016
// Problem 1.1

// wikipedia
// Java: Class java.math.BigInteger (integer), Class java.math.BigDecimal (decimal)

import java.math.BigInteger;

public class Euclid {
  static BigInteger zero = new BigInteger("0");

  // from notes
  public static BigInteger gcd(BigInteger a, BigInteger b) {
    while (!a.equals(b)) {
      if (a.equals(zero)) { return b; }
      if (b.equals(zero)) { return a; }
      if (a.compareTo(b) == -1) {
        b = b.subtract(a);
      } else {
        a = a.subtract(b);
      }
    }
    return a;
  }

  // more efficient
  public static BigInteger gcd1(BigInteger a, BigInteger b) {
    BigInteger r = a.mod(b);
    while (!r.equals(zero)) {
      a = b;
      b = r;
      r = a.mod(b);
    }
    return b;
  }

  public static void main(String[] args) {
    // tests
    BigInteger a = new BigInteger("6");
    System.out.println(a.equals(gcd(new BigInteger("192"), new BigInteger("270"))));
    System.out.println(a.equals(gcd(new BigInteger("54"), new BigInteger("24"))));
    a = new BigInteger("2");
    System.out.println(a.equals(gcd(new BigInteger("382"), new BigInteger("190"))));
    BigInteger t1 = new BigInteger("831737489137489172");
    BigInteger t2 = new BigInteger("1765341241289412784");
    a = new BigInteger("4");
    System.out.println(a.equals(gcd(t1,t2)));
  }
}
