(*
    Steven Abreu
    Fibonacci
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*--------------------Problem 4.4.1--------------------*)

(* returns the nth fib number *)
(* exponential algorithm*)
fun exp_fib n = if n = 0 then 0 else if n < 3 then 1 else exp_fib(n-1) + exp_fib(n-2);

(* linear algorithm *)
local
  fun lin_fib(n, step, prev, curr) = if n = step then curr else lin_fib(n, step+1, curr, curr+prev)
in
  fun fib n = if n = 0 then 0 else lin_fib(n-1,0,0,1)
end;

(*--------------------helper functions-----------------*)

(*returns n fib numbers in a list*)
fun fibSeq n = if n = 0 then [0] else fib(n)::fibSeq(n-1);

(*gets first element of a list*)
fun head (h::t) = h;

(*returns all fib numbers <= to n*)
fun fibUpTo (n,r) = if head(fibSeq(r)) >= n then fibSeq(r) else fibUpTo(n,r+1);

(*--------------------Problem 4.4.2--------------------*)

(*checks if n is a fib number*)
fun isFib(n) = if head(fibUpTo(n,0)) = n then true else false;

(*--------------------test calls-----------------------*)
isFib(0);
isFib(1);
isFib(2);
isFib(3);
isFib(13);
isFib(55);
isFib(144);
isFib(4);
isFib(50);
isFib(67);
isFib(150);
fib(0);
fib(1);
fib(2);
fib(3);
fib(4);
fib(5);
fib(6);
fib(7);
fib(8);
