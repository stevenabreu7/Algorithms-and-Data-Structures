/*
  CH08-320142
  a2_p4.cpp
  Steven Abreu
  s.abreu@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>

using namespace std;

string replaceVowels(string l) {
  string s = "";
  int i, ll = l.length();
  for (i=0;i<ll;i++) {
    char j = l[i];
    if ((j=='a') | (j=='e') | (j=='i') | (j=='o') | (j=='u')) {
      s += '_';
    } else {
      s += j;
    }
  }
  return s;
}

int main() {
  string rds, guess;
  int rdn, tries = 0;
  int n = 15;
  string lw[] = {"computer", "television", "keyboard", "magazine", "book",
          "hello", "goodbye", "table", "chair", "monitor",
          "lamp", "couch", "window", "MacBook", "pencil"};
  srand(static_cast<unsigned int>(time(0)));

  while (true) {
    rdn = (rand() % n);
    rds = lw[rdn];

    cout << replaceVowels(rds) << endl;

    cin >> guess;
    tries++;

    if (guess == rds) {
      cout << "Correct! Tries: " << tries << "." << endl;
      cout << "Would you like to play again? (y/n)" << endl;
      tries = 0;
      string answer;
      cin >> answer;
      //what to do with the answer? -> give y/n option.
      //n -> quit game, anything else -> continue game
      if (answer == "n") {
        return 0;
      }
    } else if (guess == "quit") {
      return 0;
    } else {
      cout << "Wrong answer, try this one." << endl;
    }
  }

}
