(*
    Steven Abreu
    Alternating Sum
    Gen CS Fall 2016
    Jacobs University Bremen
*)

fun alternate l =
  let
    fun altPlus [] = 0
      | altPlus (h::t) = h + altMinus t
    and altMinus [] = 0
      | altMinus (h::t) = ~h + altPlus t
  in
    altPlus l
  end;

(* Should be 4 *)
val testResult = alternate [1,2,3,4,5,6,7];
