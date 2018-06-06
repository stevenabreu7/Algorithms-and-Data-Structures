(*
    Steven Abreu
    Second Maximum
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*
  Grading:
  Exception raised when there's only two
  elements in your list (which should not occur).
*)

exception noSuchElement;

val x = 1.325;
val t = 3.124;

(*checks whether element is the highest in a list*)
fun isHighest (_,nil) = raise noSuchElement
  | isHighest (a:real,xs::nil) = a >= xs
  | isHighest (a,xs::x) = if a >= xs then isHighest(a,x) else false;

(*gets the highest element of a list*)
fun highest nil = raise noSuchElement
  | highest (xs::x) = if isHighest(xs,x) then xs else highest(x);

(*removes an element from a list*)
fun rm (_,nil) = raise noSuchElement
  | rm (a,xs::x) = if Real.==(a,xs) then x else xs::rm(a,x);

(*returns the second highest element of the list*)
fun s_max nil = raise noSuchElement
  | s_max (x::nil) = raise noSuchElement
  | s_max (lst:real list) = highest(rm(highest(lst),lst));

s_max [1.0,4.4,4.5,6.2,2.3,2.2,2.2];
