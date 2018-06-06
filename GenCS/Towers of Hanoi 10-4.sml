(*
  Steven Abreu
  Problem 10.4 - Towers of Hanoi
  Gen CS Fall 2016
  Jacobs University Bremen
*)

(*
move disk function:
this function actually moves one disk to another rod.
it moves it from the a to the c rod (for the function call
-> depending on the depth of recursion in which moveDisk is
called, this may be different rods than a (leftmost) or c
(rightmost rod)).
*)

(*
move function:
move the tower recursively. this branches out into (2^n)-1
branches resulting in 2^n - 1 calls of moveDisk which is
exactly the minimal number of moves required to solve this
problem. it changes the a,b,c rods recursively in a way that
solves this problem.
*)

local
  fun moveDisk(a,c) = (a,c)::nil;
  fun move(0,a,b,c) = nil
    | move(n,a,b,c) = move(n-1,a,c,b) @ moveDisk(a,c) @ move(n-1,b,a,c);
in
  fun moveTower(h) = move(h,1,2,3);
end;

moveTower 1;
moveTower 2;
moveTower 3;
moveTower 4;
moveTower 5;
