#include <string> // defines standard C++ string class

/* First C++ class */
class City
{
private:  // data members are private
	std::string name;
  int inhabitants;
  std::string location;
  std::string poi;

public: // business logic methods are public
	// setter methods
  void setName(std::string& newname);
	void setInhabitants(int newInhabitants);
	void setLocation(std::string& newLocation);
  void setPOI(std::string& newPOI);
	// getter method
	std::string getName();
  int getInhabitants();
  std::string getLocation();
  std::string getPOI();
	// service method
	void print();
};
