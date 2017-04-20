(*
Steven Abreu
Jacobs University Bremen
AaDS Fall 2016
Problem 1.2
*)

(*algorithm from 1.1*)
fun gcd(a,b) = let val (_,r) = IntInf.quotRem(a, b) in if r=0 then b else gcd(b,r) end;

(*exception for when denominator is zero*)
exception illegalDenominator;
(*datatype declaration*)
datatype rational = rational of IntInf.int * IntInf.int;

(*constructor*)
fun MakeRational(d:IntInf.int, e:IntInf.int) =
      if IntInf.<=(e,0) then
        raise illegalDenominator
      else
        rational(d,e);

fun equal(rational(d1,e1),rational(d2,e2)) = (d1*e2 = e1*d2);

fun normal(rational(d,e)) =
      let
        val g = gcd(d,e)
        val (dr,_) = IntInf.divMod(d,g)
        val (er,_) = IntInf.divMod(e,g)
      in MakeRational(dr,er) end;

fun add(rational(d1,e1),rational(d2,e2)) = MakeRational(d1*e2+e1*d2,e1*e2);

fun mult(rational(d1,e1),rational(d2,e2)) = MakeRational(d1*d2,e1*e2);

fun addInv(rational(d,e)) = MakeRational(~d,e);

fun multInv(rational(d,e)) = MakeRational(e,d);
