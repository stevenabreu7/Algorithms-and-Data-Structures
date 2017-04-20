(*
Steven Abreu
Jacobs University Bremen
AaDS Fall 2016
Problem 1.1
*)

(*wikipedia:
Standard ML: The optional built-in IntInf structure implements the INTEGER
signature and supports arbitrary-precision integers.*)

(*from notes*)
fun gcd(a,b:IntInf.int) = if a = b then a else if a < b then gcd1(a,b-a) else gcd1(a-b,b);

(*more efficient*)
fun gcd1(a,b) = let val (_,r) = IntInf.quotRem(a, b) in if r=0 then b else gcd(b,r) end;

(*tests*)
6 = gcd(192,270);
6 = gcd(54,24);
2 = gcd(382,190);
4 = gcd(831737489137489172,1765341241289412784);
