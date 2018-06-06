(*
    Steven Abreu
    Decoder & Encoder
    Gen CS Fall 2016
    Jacobs University Bremen
*)

exception OutOfRange;
exception CodeOutOfRange;

(*head function*)
fun h nil = raise OutOfRange
  | h(h::t) = h;

(*tail function*)
fun tl nil = raise OutOfRange
  | tl(h::t) = t;

(*encode a string using the character code in the list l*)
local
  fun enc(nil,l,s1) = raise CodeOutOfRange
    | enc(_,_,"") = nil
    | enc((hc,hs)::t,l,s1) =
      if hc=(h(explode(s1)))
        then hs::enc(l,l,implode(tl(explode(s1))))
      else enc(t,l,s1);
in
  fun encode(l,s) = enc(l,l,s)
end;

(*check if first string is a prefix of the second string. this returns the result
as a boolean and also the remainder of the second string. both strings are
actually char lists.*)
fun prefix(nil,x) = (true,x)
  | prefix(_,nil) = (false,nil)
  | prefix(xs::x:char list, ys::y) = if xs = ys then prefix(x,y) else (false,ys::y);

(*decode a string using the character code in the list l*)
local
  fun dec(nil,l,s) = raise CodeOutOfRange
    | dec(_,_,"") = nil
    | dec((hc,hs)::t,l,s) =
      let
        val codedList = explode(s)
        val codeword = explode(hs)
        val (isPrefix,remCodedList) = prefix(codeword,codedList)
      in
        if isPrefix then
          hc::dec(l,l,implode(remCodedList)) else
          dec(t,l,s)
      end
in
  fun decode(code,s) = implode(dec(code,code,s))
end;

val code =
[(#"a","00001"), (#"b","01010"), (#"c","10100"),
(#"d","00100"), (#"e","1110"), (#"f","01001"),
(#"g","00101"), (#"h","1001"), (#"i","10111"),
(#"j","01111"), (#"k","10101"), (#"l","00000"),
(#"m","01100"), (#"n","01000"), (#"o","110"),
(#"p","01101"), (#"q","10110"), (#"r","11111"),
(#"s","00010"), (#"t","1000"), (#"u","11110"),
(#"v","00011"), (#"w","01011"), (#"x","01110"),
(#"y","00111"), (#"z","00110")];

encode(code,"notbad");
decode(code,"010001101000010100000100100");
