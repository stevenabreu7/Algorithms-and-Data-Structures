(*
    Steven Abreu
    Angry Birds
    Gen CS Fall 2016
    Jacobs University Bremen
*)

(*blue int: how many blue birds hit an object
yellow bool: whether or not it hit a pig
white: 0,
yellow: true: 2500, false: 0
blue: int * 1000
red: 5000*)
datatype angrybird = white | red | blue of int | yellow of bool;

(*----------------helper functions---------------*)

(*checks if x is the biggest value in the list *)
fun isBiggest(x,nil) = true
  | isBiggest(x,h::t) = if x>=h then isBiggest(x,t) else false;

(*get the biggest element in a list.
returns ~1 if list is empty (not gonna happen here)*)
fun getBiggest nil = ~1
  | getBiggest (h::t) = if isBiggest(h,t) then h else getBiggest(t);

(*remove x from list*)
fun remove(x,nil) = nil
  | remove(x:int,h::t) = if x=h then t else h::remove(x,t);

(*sort a list with the biggest value in first place*)
fun sortDescending (nil) = nil
  | sortDescending (lst) =
      let
        val biggest = getBiggest(lst)
        val restOfL = remove(biggest,lst)
      in
        biggest::sortDescending(restOfL)
      end;

(*converts angrybird datatype to integer (->score)*)
fun getBirdScore (white) = 0
  | getBirdScore (red) = 5000
  | getBirdScore (blue be) = be * 1000
  | getBirdScore (yellow ye) = if ye then 2500 else 0;

(*converts the birdList into a list of scores for each bird*)
fun birdToScoreList nil = nil
  | birdToScoreList (h::t) = getBirdScore(h) :: birdToScoreList(t);

(*returns the first k elements of a list*)
fun firstElements(_, nil) = 0
  | firstElements(0,_) = 0
  | firstElements(k,h::t) = h + firstElements(k-1,t);

(*----------------actual function----------------*)

(*function should return the maximum score possible by firing k:int
of the angrybirds in the list.*)
fun getScore (nil,_) = 0
  | getScore (_, 0) = 0
  | getScore (l,k) =
      let
        val scoreList = birdToScoreList(l)
        val sortedList = sortDescending(scoreList)
        val resultSum = firstElements(k,sortedList)
      in
        resultSum
      end;

(*----------------test calls---------------------*)
getScore([white, white, red, blue(3)],3);
getScore([red, yellow(false), yellow(true), blue(2)],2);
