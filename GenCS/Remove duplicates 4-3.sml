(*
    Steven Abreu
    Remove Duplicates
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*-----------helper functions-----------*)
fun hasDupes(el,[]) = false
  | hasDupes(el, h::t) = if el = h then true else hasDupes(el,t);

fun noDupes(e,[]) = []
  | noDupes(e,h::t) = if e = h then noDupes(e,t) else h::noDupes(e,t);

(*-----------actual function------------*)
fun remove_duplicates [] = []
  | remove_duplicates (h::t) = if hasDupes(h,t) then h::remove_duplicates(noDupes(h,t)) else h::remove_duplicates(t);

(*-----------test calls-----------------*)
remove_duplicates([true,true,false]);
remove_duplicates([5,3,12,3,3,2,5,5,5]);
