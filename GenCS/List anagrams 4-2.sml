(*
    Steven Abreu
    Anagrams
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*---------------------------------------------------------------*)
(*------------------------helper functions-----------------------*)
(*---------------------------------------------------------------*)

(*checks if element is in this list*)
fun elOf(s,[]) = false
  | elOf(s,h::t) = if s = h  then true else elOf(s,t);

(*removes element from list*)
fun rem(s,[]) = []
  | rem(s,h::t) = if s = h then t else h::rem(s,t);

(*removes sublist from list*)
fun remSub(_,[]) = []
  | remSub([],l) = l
  | remSub(h::t, l) = if elOf(h,l) then remSub(t,rem(h,l)) else h::remSub(t,l);

remSub([1,2,3,4],[1,2,3,4,5,6,7,8]);

(*checks if lists contain same elements*)
fun containSame ([],[]) = true
  | containSame ([],h::t) = false
  | containSame (h::t,[]) = false
  | containSame (h::t, l) = if elOf(h,l) then containSame(t,rem(h,l)) else false;

(*checks if two strings contain same elements*)
fun areAnagrams(s,t) = containSame(explode(s), explode(t));

(*checks if string has an anagram in the list -> bool*)
fun hasAnagramIn(s,[]) = false
  | hasAnagramIn(s:string, h::t) = if areAnagrams(s,h) then true else hasAnagramIn(s,t);

(*checks if string has an anagram in list -> list of anagrams*)
fun getAnagramList(s,[]) = nil
  | getAnagramList(s:string,h::t) = if areAnagrams(s,h) then h::getAnagramList(s,t) else getAnagramList(s,t);

(*---------------------------------------------------------------*)
(*------------------------actual function------------------------*)
(*---------------------------------------------------------------*)
fun listAnagrams [] = nil
  | listAnagrams (h::t) = if hasAnagramIn(h,t) then
      let
        val list = getAnagramList(h,t)
        val subset = h::list
        val clearedTail = remSub(list,t)
      in
        subset::listAnagrams(clearedTail)
      end
    else [h]::listAnagrams(t);

(*------------------------test calls-----------------------------*)
listAnagrams(["algorithm", "listen", "logarithm", "something", "silent", "Silent", "lentis"]);
