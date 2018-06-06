#include <iostream>
#include <cstdlib>
#include "City.h"

using namespace std;

int main(int argc, char** argv)
{
    City br, h, be;

    string name, location, poi; //dont need spaces
    int inhabitants;

    cout << "Please enter data for Bremen: " << endl;
    name = "Bremen";
    cout << "Location: ";
    cin >> location;
    cout << "POI: ";
    cin >> location;
    cout << "Inhabitants: ";
    cin >> inhabitants;

    br.setName(name);
    br.setLocation(location);
    br.setPOI(poi);
    br.setInhabitants(inhabitants);

    cout << "You have created Bremen:" << endl;
    br.print();

    cout << "Please enter data for Berlin: " << endl;
    name = "Berlin";
    cout << "Location: ";
    cin >> location;
    // getline(cin, location);
    cout << "POI: ";
    cin >> poi;
    // getline(cin, poi);
    cout << "Inhabitants: ";
    cin >> inhabitants;

    be.setName(name);
    be.setLocation(location);
    be.setPOI(poi);
    be.setInhabitants(inhabitants);

    cout << "You have created Berlin:" << endl;
    be.print();

    cout << "Please enter data for Hamburg: " << endl;
    name = "Hamburg";
    cout << "Location: ";
    // getline(cin, location);
    cin >> location;
    cout << "POI: ";
    // getline(cin, poi);
    cin >> poi;
    cout << "Inhabitants: ";
    cin >> inhabitants;

    h.setName(name);
    h.setLocation(location);
    h.setPOI(poi);
    h.setInhabitants(inhabitants);

    cout << "You have created Hamburg:" << endl;
    h.print();
    return 0;
}
