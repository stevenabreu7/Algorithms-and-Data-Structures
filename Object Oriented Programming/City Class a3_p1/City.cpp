#include <iostream>
#include "City.h"

using namespace std;

// setter methods
void City::setName(std::string& newname) {
  name = newname;
}

void City::setInhabitants(int newInhabitants) {
  inhabitants = newInhabitants;
}

void City::setLocation(string& newLocation) {
  location = newLocation;
}

void City::setPOI(string& newPOI) {
  poi = newPOI;
}

// getter method
string City::getName() {
  return name;
}

int City::getInhabitants() {
  return inhabitants;
}

string City::getLocation() {
  return location;
}

string City::getPOI() {
  return poi;
}

// service method
void City::print() {
  cout << "This is " << name << ". " << name << " has " << inhabitants <<
    " inhabitants. One location in " << name << " is " << location <<
    ". A POI is " << poi << "." << endl;
}
