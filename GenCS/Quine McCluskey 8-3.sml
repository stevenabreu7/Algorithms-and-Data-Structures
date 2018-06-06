(*
  Steven Abreu
  Quine McCluskey
  Jacobs University Bremen
  General Computer Science Fall 2016
*)

val placeX = 8;
(*fake exception to not have the non-exhaustive match warning*)
exception InvalidInput;
(*could have handled the errors properly..*)
exception error;

(*getDNFs from the original input in the QuineMcCluskey function*)
fun getDNF(nil) = nil
  | getDNF((lst,0)::t) = getDNF(t)
  | getDNF((lst,1)::t) = lst::getDNF(t)
  | getDNF(x) = raise InvalidInput;

(*checks two monomials for equality*)
fun monEq(nil: int list,nil) = true
  | monEq(xs::x,ys::y) = if xs=ys then monEq(x,y) else false
  | monEq(_,_) = false;

(*checks two lists of monomials for equality*)
fun monListEq(nil,nil) = true
  | monListEq(xs::x,ys::y) = if monEq(xs,ys) then monListEq(x,y) else false
  | monListEq(_,_) = false;

(*remove monomial from monomial list*)
fun remove(x,nil) = nil
  | remove(x,h::t) = if monEq(x,h) then t else h::remove(x,t);

(*checks if two monomials are partners (if they differ in exactly one literal)*)
local
  fun a(nil:int list,nil,1) = true
    | a(nil,nil,n) = false
    | a(xs::x,ys::y,n) = if xs=ys
        then a(x,y,n)
        else a(x,y,n+1)
    |a (_,_,_) = raise InvalidInput;
in
  fun arePartners(x,y) = a(x,y,0)
end;

(*checks if monomial has partners in list of monomials - uses arePartners*)
fun hasPartners(m,nil) = false
  | hasPartners(m,h::t) = if arePartners(m,h) then true else hasPartners(m,t);

(*returns the cancelled monomial of two partner monomials*)
fun cancel(nil,nil) = nil
  | cancel(xs::x,ys::y) = if xs=ys
      then xs::cancel(x,y)
      else placeX::cancel(x,y)
  | cancel(_,_) = raise InvalidInput;

(*returns the list of cancelled monomials of one monomial and other monomials
if they arent partners, then nothing will be returned*)
fun cancels(m,nil) = nil
  | cancels(m,h::t) = if arePartners(m,h)
      then cancel(m,h)::cancels(m,t)
      else cancels(m,t);

(*check if 1 is a cancellation of 2
this is true if they differ in only one value and 1 has that value
set to the placeX value*)
fun isCancellationOf(nil,nil,1,true) = true
  | isCancellationOf(nil,nil,_,_) = false
  | isCancellationOf(xs::x,ys::y,n,b) = if xs=ys
      then isCancellationOf(x,y,n,b)
      else if xs=placeX then isCancellationOf(x,y,n+1,true)
      else false
  |isCancellationOf(_,_,_,_) = raise InvalidInput;

(*checks if list contains cancellations of the given monomial*)
fun hasCancellation(m,nil) = false
  | hasCancellation(m,h::t) = if isCancellationOf(m,h,0,false)
      then true
      else hasCancellation(m,t);

(*checks if monomial is a cancellation of any of the monomials in the list*)
fun isCancellation(m,nil) = false
  | isCancellation(m,h::t) = if isCancellationOf(h,m,0,false)
      then true
      else isCancellation(m,t);

(*get cancellation of the monomial that is in the list*)
fun getCancellation(m,nil) = raise error
  | getCancellation(m,h::t) = if isCancellationOf(m,h,0,false)
      then h
      else getCancellation(m,t);

(*check and remove all cancellations in a given list of monomials*)
fun checkCancellations(nil) = nil
  | checkCancellations(h::t) = if isCancellation(h,t)
      then checkCancellations(t)
      else if hasCancellation(h,t)
        then checkCancellations(remove(getCancellation(h,t),h::t))
      else h::checkCancellations(t);

(*check is a monomial is in the monomialList*)
fun monomialMember(x, nil) = false
  | monomialMember(x,h::t) = if monEq(x,h) then true else monomialMember(x,t);

(*remove all duplicate monomials from monomialList*)
fun removeDuplicates(nil:int list list) = nil
  | removeDuplicates(h::t) = if monomialMember(h,t)
      then h::removeDuplicates(remove(h,t))
      else h::removeDuplicates(t);

(*after applying the algorithm, we need to clean up.
-> This means removing all duplicates
& removing all monomials that had been partnered up and cancelled*)
local
  fun apply(nil) = nil
    | apply(h::t) =
      let
        val cancellations = cancels(h,t)
      in
        if hasPartners(h,t)
        (*has partners - dont add itself, but add cancellations with other partners*)
        then cancels(h,t) @ apply(t)
        (*has no partners -> just add itself*)
        else h::apply(t)
      end
  fun cleanApply(l) = removeDuplicates(checkCancellations(apply(l)));
in
  (*if applying QMC1 doesnt change the list anymore -> stop*)
  fun QMC1(l) = if monListEq(l,cleanApply(l)) then l else QMC1(cleanApply(l))
  (*fun QMC1(l) = cleanApply(l);*)
end;

(*------------------------------------------------------------------------------------*)
(*--------------------------------------QMC2------------------------------------------*)
(*------------------------------------------------------------------------------------*)

(*logical and for 0=F, not0=T*)
fun or(0,_) = 0
  | or(1,_) = 1;

(*counts elements in list*)
fun count nil = 0
  | count (h::t) = 1+count(t);

(*if it reaches end of truth values, return 1.
if values are same -> continue. if values differ -> return 0*)
(*gets the value of an individual cell in the QMC2 table. (value of
one specific monomial for one specific truth value combination)*)
fun evaluateMonomialForTruthValues(nil,nil) = 1
  | evaluateMonomialForTruthValues(xs::x,ys::y) = if xs=ys
      then evaluateMonomialForTruthValues(x,y)
      else if xs=placeX then evaluateMonomialForTruthValues(x,y)
      else 0
  | evaluateMonomialForTruthValues(_,_) = raise InvalidInput;

(*returns 1 if there is at least one true value in the column of the QMC2 table
for a specific truth value combination*)
local
fun helperA(nil,_) = 0
  | helperA(xs::x,tv) = evaluateMonomialForTruthValues(xs,tv) + helperA(x,tv);
in
  fun evaluateMonomialsForTruthValues(a,b) = if helperA(a,b) > 0 then 1 else 0
end;

(*returns true if the monomials fulfill the given QMC2 table*)
fun evaluateMonomialsForTruthTable(_,nil) = true
  | evaluateMonomialsForTruthTable(m,tv::tt) = if evaluateMonomialsForTruthValues(m,tv)=1
      then evaluateMonomialsForTruthTable(m,tt)
      else false;

(*QMC2 has to be called with the list of monomials (result of QMC1), the
DNF list (easily obtained from the user input on the QuineMcCluskey function),
and the number of monomials in the monomialList*)
fun QMC2(monList,_,0) = monList
  | QMC2(h::monList,dnfList,n) = if evaluateMonomialsForTruthTable(monList,dnfList)
      then QMC2(monList,dnfList,n-1)
      else QMC2(monList @ h::nil,dnfList,n-1)
  | QMC2(_,_,_) = raise InvalidInput;

(*this formats a monomial to a string, as in the example*)
local
  fun aHelper(nil,_) = ""
    | aHelper(0::t,n) = concat("(-x"::Int.toString(n)::")"::aHelper(t,n+1)::nil)
    | aHelper(1::t,n) = concat("x"::Int.toString(n)::aHelper(t,n+1)::nil)
    | aHelper(x::t,n) = aHelper(t,n+1);
in
  fun monToString(l) = aHelper(l,1)
end;

(*convert the result of the QuineMcCluskey function to a string, formatted as in the example*)
fun resultToString(nil) = ""
  | resultToString(h::nil) = monToString(h)
  | resultToString(h::t) = concat(monToString(h)::" + "::resultToString(t)::nil);

(*------------------------------------------------------------------------------------*)
(*--------------------------------------FINAL-----------------------------------------*)
(*------------------------------------------------------------------------------------*)

(*the final function!!*)
fun QuineMcCluskey(l) =
      let
        val dnf = getDNF(l)
        val monList = QMC1(dnf)
        val n = count(monList)
        val res2 = QMC2(monList,dnf,n)
      in
        resultToString(res2)
      end;

(*------------------------------------------------------------------------------------*)
(*--------------------------------------TESTS-----------------------------------------*)
(*------------------------------------------------------------------------------------*)

val l1 = [([0,0,0,0],1),([0,0,0,1],0),([0,0,1,0],0),([0,0,1,1],1),([0,1,0,0],0),([0,1,0,1],0),([0,1,1,0],1),([0,1,1,1],1),
              ([1,0,0,0],0),([1,0,0,1],1),([1,0,1,0],0),([1,0,1,1],1),([1,1,0,0],1),([1,1,0,1],0),([1,1,1,0],1),([1,1,1,1],0)];
val l2 = [([0,0,0,0],1),([0,0,0,1],1),([0,0,1,0],1),([0,0,1,1],0),([0,1,0,0],0),([0,1,0,1],1),([0,1,1,0],0),([0,1,1,1],0),
              ([1,0,0,0],0),([1,0,0,1],0),([1,0,1,0],1),([1,0,1,1],1),([1,1,0,0],0),([1,1,0,1],0),([1,1,1,0],1),([1,1,1,1],1)];
val demo = [([0,0], 1),([0,1], 0),([1,0], 0),([1,1], 1)];

(*val r1 = [[0,0,0,0],[8,0,1,1],[0,1,1,8],[1,0,8,1],[1,1,8,0]];*)
val r1 = "(-x1)(-x2)(-x3)(-x4) + (-x2)x3x4 + (-x1)x2x3 + x1(-x2)x4 + x1x2(-x4)";
QuineMcCluskey l1;
(*val r2 = [[0,0,8,0],[0,8,0,1],[1,8,1,8]];*)
val r2 = "(-x1)(-x2)(-x4) + (-x1)(-x3)x4 + x1x3";
QuineMcCluskey l2;
val dr = "(-x1)(-x2) + x1x2";
QuineMcCluskey demo;
