#include <iostream>
#include "TournamentMember.h"

using namespace std;

int main() {
  char f1[] = "Steve";
  char l1[] = "Abreu";
  char b1[] = "1997-07-24";
  char f2[] = "Barack";
  char l2[] = "Obama";
  char b2[] = "1900-01-01";
  char f3[] = "Michael";
  char l3[] = "Jackson";
  char b3[] = "1900-01-01";
  char fr[] = "Angela";
  char lr[] = "Merkel";
  char br[] = "1900-01-01";
  Player a(f1, l1, b1, 1.8, 87, 7, 4, 0, true);
  Player b(f2, l2, b2, 1.8, 80, 1, 1, 2, false);
  Player c(f3, l3, b3, 1.85, 75, 9, 4, 11, true);
  a.changeLocation("Bremen");

  Player* ap = &a;
  Player* bp = &b;
  Player* cp = &c;

  Referee r(fr, lr, br, 1.69, 60);

  r.addToYellowCardList(ap);
  r.addToYellowCardList(ap);
  r.addToYellowCardList(ap);
  r.addToRedCardList(ap);

  cout << endl;

  r.addToRedCardList(bp);

  cout << endl;

  r.addToYellowCardList(cp);
  r.addToRedCardList(cp);

  return 0;
}
