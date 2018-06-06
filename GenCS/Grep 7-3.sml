(*
    Steven Abreu
    Simple Grep
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*checks if l2 contains the exact sequence of l1 from the beginning*)
fun grepableHelper (l,nil,_) = true
  | grepableHelper (l,_,nil) = false
  | grepableHelper (l,xs::x, ys::y) = if xs = ys then grepableHelper(l,x,y) else grepable(l,y)

(*checks if l2 contains the exact sequence of l1 somewhere*)
and grepable (nil, _) = true
  | grepable (_,nil) = false
  | grepable (xs::x: char list, ys::y) = if xs = ys then grepableHelper(x,x,y) else grepable(xs::x,y);

(*checks if s1 is a substring of s2*)
fun substring (s1, s2) = grepable(explode(s1), explode(s2));

(*grep functions for pattern and string input*)
fun grepString (pattern:string, instring:string) =
  let
    val returnMessage = if substring(pattern,instring) then instring else "";
  in
    print(returnMessage)
  end;

fun grep(pattern, infile, outfile) =
  let
    val ins = TextIO.openIn infile
    val outs = TextIO.openOut outfile
    fun helper(copt: string option) =
      case copt of
          NONE => (TextIO.closeIn ins; TextIO.closeOut outs)
        | SOME(str) =>
            if substring(pattern,str) then
              (TextIO.output(outs,str);helper(TextIO.inputLine ins))
            else
              (helper(TextIO.inputLine ins))
  in
    helper(TextIO.inputLine ins)
  end;

grep("substring","in.txt", "out.txt");
