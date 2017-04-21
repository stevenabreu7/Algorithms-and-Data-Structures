(*
    Steven Abreu
    Assignment 4.2
    March 7th 2017
*)

(*Inductively defined datatype for lists in SML*)
datatype 'a iList = nl | cns of 'a * 'a iList;

(*concat two lists*)
fun concat(x, nl) = x
  | concat(nl, y) = y
  | concat(cns(x,xs), y) = cns(x,concat(xs,y));

(*reverse the list*)
fun reverse(nl) = nl
  | reverse(cns(x,xs)) = concat(reverse(xs), cns(x, nl));

(*get number of elements in list*)
fun dep(nl) = 0
  | dep(cns(x,xs)) = 1 + dep(xs);

(*simple power function *)
fun pow(x,0) = 1
  | pow(x,n) = x * pow(x,n-1);

(*function to represent the list as one big number
only works for the test cases in which all list elements
are smaller than 10*)
fun repr(nl) = 0
  | repr(cns(x,nl)) = x
  | repr(cns(x,xs)) = x * pow(10,dep(cns(x,xs))-1) + repr(xs);

(*TEST CASES*)
val la = cns(2,cns(4,cns(5, nl)));
val lb = cns(3,cns(5,cns(6,nl)));
val lc = concat(la,lb);
val lar = reverse(la);
val rla = repr(la);
val rlb = repr(lb);
val rlc = repr(lc);
val rlar = repr(lar);
