#include <iostream>
#include <string.h>
#include "TournamentMember.h"

using namespace std;

string TournamentMember::location = "Washington, D.C.";

TournamentMember::~TournamentMember() {
  cout << "--destructor call--" << endl;
}

TournamentMember::TournamentMember(const TournamentMember& t) {
  strcpy(firstName, t.firstName);
  strcpy(lastName, t.lastName);
  strcpy(birthdate, t.birthdate);
  height = t.height;
  weight = t.weight;
  cout << "--copy constructor call--" << endl;
}

TournamentMember::TournamentMember(char f[], char l[], char b[], double h,
    double w) : height(h), weight(w) {
  strcpy(firstName, f);
  strcpy(lastName, l);
  strcpy(birthdate, b);
  cout << "--parameter constructor call--" << endl;
}

void TournamentMember::print() const {
  cout << "Name: " << firstName << " " <<
    lastName << ".\nBirthdate: " << birthdate << ".\nHeight: " << height <<
    "m.\nWeight: " << weight << "kg." << endl;
}

void TournamentMember::setFirstName(char f[]) { strcpy(firstName, f); }

void TournamentMember::setLastName(char l[]) { strcpy(lastName, l); }

void TournamentMember::setBirthdate(char b[]) { strcpy(birthdate, b); }

// ----------------------------PLAYER--------------------------------

Player::Player(char f[], char l[], char b[], double h, double w, int n, int p,
    int g, bool r) : TournamentMember(f,l,b,h,w) {
  number = n;
  position = p;
  goals = g;
  rightFooted = r;
}

Player::Player(const Player& p) : TournamentMember(p) {
  number = p.number;
  position = p.position;
  goals = p.goals;
  rightFooted = p.rightFooted;
}

Player::~Player() {

}

string getYesNo(bool b) {
  return (b) ? "Yes" : "No";
}

void Player::print() {
  TournamentMember::print();
  cout << "Number: " << number << ".\nPosition: " <<
    position << ".\nGoals: " << goals << ".\nRightfooted? " <<
    getYesNo(rightFooted) << "\n\n";
}

// ----------------------------REFEREE--------------------------------

Referee::~Referee() {

}

Referee::Referee(char f[], char l[], char b[], double h, double w)
    : TournamentMember(f,l,b,h,w){
  redCardCount = 0;
  yellowCardCount = 0;
}

Player** find(Player *arr[], int start, int end, const Player *val) {
  while (arr[start] != arr[end]) {
    if (arr[start] == val) return &arr[start];
    start++;
  }
  return &arr[end];
}

bool Referee::addToYellowCardList(Player *p) {
  // Player** redresult = find(begin(redCardList), end(redCardList), p);
  Player** redresult = find(redCardList, 0, redCardCount, p);
  if (redresult == &redCardList[redCardCount]) {
    //player is not in the red card list
    //check if player has a yellow card
    // Player** sresult = find(begin(yellowCardList), end(yellowCardList), p);
    Player** sresult = find(yellowCardList, 0, yellowCardCount, p);
    if (sresult == &yellowCardList[yellowCardCount]) {
      //player is in neither list -> add to yellow
      yellowCardList[yellowCardCount] = p;
      yellowCardCount++;
      cout << "added player to yellow card list." << endl;
      cout << "count yellow: " << yellowCardCount << endl;
      cout << "count red: " << redCardCount << endl;
    } else {
      //remove from yellow card list
      yellowCardCount--;
      int i;
      bool deleted = false;
      for (i=0;i<yellowCardCount;i++) {
        if (deleted) {
          yellowCardList[i] = yellowCardList[i+1];
        } else {
          if (yellowCardList[i] == p) {
            yellowCardList[i] = yellowCardList[i+1];
            deleted = true;
          }
        }
      }
      //player is in yellow card list already -> add to red
      redCardList[redCardCount] = p;
      redCardCount++;
      cout << "added player to red card list." << endl;
      cout << "count yellow: " << yellowCardCount << endl;
      cout << "count red: " << redCardCount << endl;
    }
  } else {
    //player already has a red card
    cout << "player already has a red card. (yellow)" << endl;
    cout << "count yellow: " << yellowCardCount << endl;
    cout << "count red: " << redCardCount << endl;
    return false;
  }
  return true;
}

bool Referee::addToRedCardList(Player *p) {
  // Player** sresult = find(begin(redCardList), end(redCardList), p);
  Player** redresult = find(redCardList, 0, redCardCount, p);
  if (redresult == &redCardList[redCardCount]) {

    //check if player is in yellow card list
    // Player** sresult = find(begin(yellowCardList), end(yellowCardList), p);
    Player** sresult = find(yellowCardList, 0, yellowCardCount, p);
    if (sresult != &yellowCardList[yellowCardCount]) {
      //is in yellow card list -> remove!
      yellowCardCount--;
      int i;
      bool deleted = false;
      for (i=0;i<yellowCardCount;i++) {
        if (deleted) {
          yellowCardList[i] = yellowCardList[i+1];
        } else {
          if (yellowCardList[i] == p) {
            yellowCardList[i] = yellowCardList[i+1];
            deleted = true;
          }
        }
      }
    }
    //didnt find player in list
    redCardList[redCardCount] = p;
    redCardCount++;
    cout << "added player to red card list." << endl;
    cout << "count yellow: " << yellowCardCount << endl;
    cout << "count red: " << redCardCount << endl;
  } else {
    //player already in list
    cout << "player already has a red card. (red)" << endl;
    cout << "count yellow: " << yellowCardCount << endl;
    cout << "count red: " << redCardCount << endl;
    return false;
  }
  return true;
}
