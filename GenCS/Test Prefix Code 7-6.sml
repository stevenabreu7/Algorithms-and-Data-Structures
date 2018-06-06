(*
    Steven Abreu
    Test Prefix Code
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*logical and*)
fun a(true,true) = true
  | a(_,_) = false;

(*logical or*)
fun v(false,false) = false
  | v(_,_) = true;

(*check if this character is in the char*string list somewhere*)
fun memChar(x,nil) = false
  | memChar(x,(hc:char,hs)::t) = if x=hc then true else memChar(x,t);

(*check if this string is in the char*string list somewhere*)
fun memString(x,nil) = false
  | memString(x,(hc,hs:string)::t) = if x=hs then true else memString(x,t);

(*no character is defined twice - I wont check for same chars pointing to same
string since there really is no point in entering duplicate entries here*)
fun isFunction nil = true (*empty function is a function!*)
  | isFunction ((hc,hs)::t) = if memChar(hc,t) then false else isFunction(t);

(*every string is only in there once - won't to check for duplicate entries*)
fun isInjective nil = true (*empty function is injective*)
  | isInjective ((hc,hs)::t) = if memString(hs,t) then false else isInjective(t);

(*checks if string 1 is a proper prefix of string 2*)
fun isProperPrefix("","") = false
  | isProperPrefix("",_) = true
  | isProperPrefix(s1,s2) =
    let
      val xs::x = explode(s1)
      val ys::y = explode(s2)
    in
      if xs = ys then isProperPrefix(implode(x),implode(y)) else false
    end;

(*checks if string has or is proper prefix of any other strings in list*)
fun hasProperPrefix(x,nil) = false
  | hasProperPrefix(x,(_,h)::t) =
    if v(isProperPrefix(x,h),isProperPrefix(h,x))
      then true
    else hasProperPrefix(x,t);

(*check for prefix property -> check if this string is a proper prefix of any
other string in the list*)
fun isPrefixCode nil = true (*empty code is a prefix code per def. 7.2.6*)
  | isPrefixCode ((hc,hs)::t) =
    if hasProperPrefix(hs,t)
      then false
    else isPrefixCode(t);

(*input is a (char*string) list*)
fun prefix_code nil = true (*???????*)
  | prefix_code (l) = a(a(isFunction(l),isPrefixCode(l)),isInjective(l));

prefix_code [(#"a","0"),(#"b","1")];
prefix_code [
  (#"a","010010010101001"), (#"b","010110010101001"),
  (#"c","010011110101001"), (#"d","010010011101001"),
  (#"e","010010010110001"), (#"f","010010010101101"),
  (#"g","010011110101000"), (#"h","011111110101000")
];
prefix_code [
  (#"a","00001"), (#"b","01010"), (#"c","10100"),
  (#"d","00100"), (#"e","1110"), (#"f","01001"),
  (#"g","00101"), (#"h","1001"), (#"i","10111"),
  (#"j","01111"), (#"k","10101"), (#"l","00000"),
  (#"m","01100"), (#"n","01000"), (#"o","110"),
  (#"p","01101"), (#"q","10110"), (#"r","11111"),
  (#"s","00010"), (#"t","1000"), (#"u","11110"),
  (#"v","00011"), (#"w","01011"), (#"x","01110"),
  (#"y","00111"), (#"z","00110")
];
