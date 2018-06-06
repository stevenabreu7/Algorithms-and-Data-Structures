(*
    Steven Abreu
    Mutual Recursion
    Gen CS Fall 2016
    Jacobs University Bremen
*)

exception invalidInput;

(*h-function*)
fun H 0 = 0
  | H n = if n > 0 then n - H(H(H(n-1))) else raise invalidInput;

(*q-function*)
fun Q 1 = 1
  | Q 2 = 1
  | Q n = if n > 2 then Q(n-Q(n-1)) + Q(n-Q(n-2)) else raise invalidInput;

(*mutual recursive functions male and female*)
fun male 0 = 0
  | male n = if n > 0 then n - female(male(n-1)) else raise invalidInput
and female 0 = 1
  | female n = if n > 0 then n - male(female(n-1)) else raise invalidInput;

(*mutually recursive functions a,b,c,d*)
fun a 0 = 1
  | a 1 = 2
  | a n = if n > 1 then a(n-2) * Q(n+1) else raise invalidInput
and b 0 = c 1
  | b 1 = c 2
  | b n = if n > 1 then c(n-2) else raise invalidInput
and c 0 = 1
  | c n = if n > 0 then a(n-1) * c(n-1) else raise invalidInput
and d 0 = 0
  | d n = if n > 0 then b(a(n)) else raise invalidInput;
