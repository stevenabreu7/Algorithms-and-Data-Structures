(*
    Steven Abreu
    Music Notes
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*constructor for noteclass (given in assignment)*)
datatype noteclass = A | B | C | D | E | F | G | sharp of noteclass | flat of noteclass;
(*octave number and noteclass*)
datatype note = note of int * noteclass;

(*----helper function----*)
fun noteclassValue A = 0
  | noteclassValue B = 2
  | noteclassValue C = 3
  | noteclassValue D = 5
  | noteclassValue E = 7
  | noteclassValue F = 8
  | noteclassValue G = 10
  | noteclassValue (sharp(n)) = noteclassValue(n) + 1
  (*flat cannot always be used! if octave=0 and n=A, then it would return a
  negative value in the end (this is fixed in the actual function below)*)
  | noteclassValue (flat(n)) = noteclassValue(n) - 1;

(*----actual function----*)
fun convert [] = []
  | convert (h::t: note list) =
      let
        val (note(oct,n)) = h
        val result = (oct * 12 + noteclassValue(n))
      in
        (*dont let the note class value be negative*)
        if noteclassValue(n) < 0 then
          oct * 12 :: convert(t)
        else
          result :: convert(t)
      end;

(*----test call----*)
convert([note(0,sharp(A)), note(1,flat(flat(B)))]);
convert([note(0,flat(flat(flat(A))))]);
