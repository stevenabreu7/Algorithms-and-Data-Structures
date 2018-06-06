(*
    Steven Abreu
    Set Operations
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*-----------helper functions-----------*)

(*check if n is in the list*)
fun isIn (n, []) = false
  | isIn (n:int, h::t) = if n = h then true else isIn(n,t);

(*deletes e from the list*)
fun deleteFromList (e, []) = []
  | deleteFromList (e:int, h::t) = if h = e then t else h::deleteFromList(e, t);

(*-----------actual functions-----------*)

fun intersect ([], _) = nil
  | intersect (h::t, list2) = if isIn(h, list2) then h::intersect(t,list2) else intersect(t,list2);

fun setdifference ([], _) = nil
  | setdifference (h::t, list2) = if isIn(h, list2) then setdifference(t, list2) else h::setdifference(t,list2);

fun union ([],[]) = nil
  | union ([], list2) = list2
  | union (h::t, list2) = h::union(t, deleteFromList(h, list2));

(*-----------test calls-----------------*)
union([1,2,3,4],[2,3,4,5,6]);
union([1,2,3,4],[2,8]);
union([3,4],[2,8,3,1,4,5]);
setdifference([1,2,3,4], [1,2,3]);
setdifference([1,2,3,4], [1,2,3,6]);
setdifference([1,2,3,4], [1,2,3,10,5,6,7]);
intersect([1,2,3,4], [3,4,5,7]);
intersect([1,2,3,4], [3,4,5]);
intersect([1,2,3,4], [3,4,5,6,7,8]);
setdifference([1,2,3], [3,4,5,6,7]);
