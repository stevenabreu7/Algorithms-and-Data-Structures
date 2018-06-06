(*
    Steven Abreu
    Boolean Formulae
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*"fix" match non exhaustive warning*)
exception error;

(*given datatype*)
datatype boolexp =  zero
                  | one
                  | plus of boolexp * boolexp
                  | times of boolexp * boolexp
                  | compl of boolexp
                  | var of int;

(*returns the higher number*)
fun higher(a,b) = if a > b then a else b;

(*logical or*)
fun orr (false, false) = false
  | orr (_,_) = true;

(*logical and*)
fun andd (true, true) = true
  | andd (_,_) = false;

(*logical negation*)
fun not(true) = false
  | not(false) = true;

(*gets element at specific index (0,1,...,n-1)*)
fun getElement (1,h::t) = h
  | getElement (m,nil) = raise error
  | getElement (n,h::t) = getElement(n-1,t);

(*converts boolean to integer*)
fun boolToInt (false) = 0
  | boolToInt (true) = 1;


(*count variables of boolean expression*)
fun countVariables (var(n)) = n
  | countVariables (zero) = 0
  | countVariables (one) = 0
  | countVariables (compl(a)) = countVariables(a)
  | countVariables (plus(a,b)) = higher(countVariables(a), countVariables(b))
  | countVariables (times(a,b)) = higher(countVariables(a), countVariables(b));

(*helper function to create list of all possible variable assignments*)
fun insertBefore(nil) = nil
  | insertBefore(h::t) = (false::h)::(true::h)::insertBefore(t);

(*returns list of list of bools*)
(*-> list of all possible variable assignments*)
fun allAssignments 0 = [nil]
  | allAssignments n = insertBefore(allAssignments(n-1));

(*evaluate with a variable assignment (list of bools)*)
fun evaluate (zero,l) = false
  | evaluate (one,l) = true
  | evaluate (plus(a,b),l) = orr(evaluate(a,l),evaluate(b,l))
  | evaluate (times(a,b),l) = andd(evaluate(a,l),evaluate(b,l))
  | evaluate (compl(a),l) = not(evaluate(a,l))
  | evaluate (var(n),l) = getElement(n,l);

(*VALID*)
(*if all are true*)
local
  fun helper (e,nil) = true
    | helper (e,h::t) = andd(evaluate(e,h),helper(e,t))
in
  fun valid e =
        let
          val allAss = allAssignments(countVariables(e))
          val helperRes = helper(e,allAss)
        in
          boolToInt(helperRes)
        end
end;

(*UNSATISFIABLE*)
(*if all are false*)
local
  fun helper (e,nil) = false
    | helper (e,h::t) = orr(evaluate(e,h),helper(e,t))
in
  fun unsatisfiable e =
        let
          val allAss = allAssignments(countVariables(e))
          val helperRes = helper(e,allAss)
        in
          boolToInt(not(helperRes))
        end
end;

(*SATISFIABLE*)
(*if at least one is true*)
local
  fun helper (e,nil) = false
    | helper (e,h::t) = orr(evaluate(e,h),helper(e,t))
in
  fun satisfiable e =
        let
          val allAss = allAssignments(countVariables(e))
          val helperRes = helper(e,allAss)
        in
          boolToInt(helperRes)
        end
end;

(*FALSIFIABLE*)
(*if at least one is false*)
local
  (*each step returns true if it evaluates to false*)
  (*one evaluates to false -> everything is true*)
  fun helper (e,nil) = false
    | helper (e,h::t) = orr(not(evaluate(e,h)),helper(e,t))
in
  fun falsifiable e =
        let
          val allAss = allAssignments(countVariables(e))
          val helperRes = helper(e,allAss)
        in
          boolToInt(helperRes)
        end
end;

(*given test calls*)
valid(plus(var(1),compl(var(1))));
falsifiable(plus(var(1),one));

(*more test calls*)
valid(plus(var(1),compl(var(1))));
unsatisfiable(plus(var(1),compl(var(1))));
falsifiable(plus(var(1),compl(var(1))));
satisfiable(plus(var(1),compl(var(1))));

valid(plus(var(1),one));
unsatisfiable(plus(var(1),one));
falsifiable(plus(var(1),one));
satisfiable(plus(var(1),one));
