(*
    Steven Abreu
    Shiny Pearls
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*declare datatype (copied from assignment)*)
datatype pearl = carved of int | opal of int | faceted of int | akoya of int;

(*---------------------------------------------------------------*)
(*------------------------helper functions-----------------------*)
(*---------------------------------------------------------------*)

(*sum of the first k elements of a list*)
fun sumOf ([],0) = 0
  | sumOf ([],k) = 0
  | sumOf (l,0) = 0
  | sumOf (h::t,k) = h + sumOf(t,k-1);

(*remove specific integer from list*)
fun remove (x,[]) = []
  | remove (x:int,h::t) = if x = h then t else h::remove(x,t);

(*find and return item in list that is > than x*)
fun getLargerElement (x,[]) = x
  | getLargerElement (x,h::t) = if x < h then getLargerElement(h,t) else getLargerElement(x,t);

(*get shininess for every possible type of pearl*)
fun getShininess (carved c) = 0
  | getShininess (opal opa) = opa * 2
  | getShininess (faceted f) = f * 4
  | getShininess (akoya a) = a * 10;

(*sort list so that largest item is in first place*)
fun sort [] = []
  | sort (h::t) =
      let
          val largest = getLargerElement(h,t)
          val newTail = remove(largest,t)
      in
        if largest = h
          then h::sort(t)
        else
          largest::sort(h::newTail)
      end;

(*sort list of pearls by their shininess*)
fun sortByShininess [] = []
  | sortByShininess (l) = sort(map getShininess l);

(*---------------------------------------------------------------*)
(*------------------------actual function------------------------*)
(*---------------------------------------------------------------*)

(*actual function - returns the shininess of the k shiniest pearls*)
fun shiny ([],0) = 0
  | shiny ([],k) = 0
  | shiny (l,0) = 0
  | shiny (l,k) = sumOf(sortByShininess(l),k);

(*------------------------test call------------------------------*)
shiny([carved(2), opal(3), faceted(1), faceted(5), akoya(2), opal(20)],3);
