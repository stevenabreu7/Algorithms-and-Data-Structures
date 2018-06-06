#ifndef __TOUR_H
#define __TOUR_H

class TournamentMember {
private:
  char firstName[25];
  char lastName[25];
  char birthdate[11];
  //two other properties
  double height;
  double weight;
  //static property
  static std::string location;
public:
  ~TournamentMember();
  TournamentMember(const TournamentMember&);
  TournamentMember(char[],char[],char[],double,double);
  //getters
  char * getFirstName() { return firstName; }
  char * getLastName() { return lastName; }
  char * getBirthdate() { return birthdate; }
  double getHeight() const { return height; }
  double getWeight() const { return weight; }
  //setters
  void setFirstName(char f[]);// { strcpy(firstName, f); }
  void setLastName(char l[]);// { strcpy(lastName, l); }
  void setBirthdate(char b[]);// { strcpy(birthdate, b); }
  void setHeight(double h) { height = h; }
  void setWeight(double w) { weight = w; }
  //others
  void print() const;
  static void changeLocation(std::string l) { location = l; }
  static void printLocation() {std::cout << "Location: " << location << "\n\n";}
};

class Player : public TournamentMember {
private:
  int number;
  int position;
  int goals;
  bool rightFooted;
public:
  Player(char[],char[],char[],double,double,int,int,int,bool);
  Player(const Player&);
  ~Player();
  //getters
  int getNumber() { return number; }
  int getPosition() { return position; }
  int getGoals() { return goals; }
  bool isRightFooted() { return rightFooted; }
  //setters
  void setNumber(int n) { number = n; }
  void setPosition(int p) { position = p; }
  void setRightFooted(bool r) { rightFooted = r; }
  //methods
  void print();
  void scored(int g) { goals += g; }
};

class Referee : public TournamentMember {
private:
  int yellowCardCount;
  int redCardCount;
  Player *yellowCardList[50];
  Player *redCardList[50];
public:
  ~Referee();
  Referee(char[],char[],char[],double,double);
  bool addToYellowCardList(Player *p);
  bool addToRedCardList(Player *p);
};

#endif
