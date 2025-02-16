#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <string>
#include <vector>
#include "MenuItem.hpp"
using namespace std;

class Restaurant {
private:
  string name;
  string address;
protected:
  vector<MenuItem> menu;
public:
  Restaurant(string name, string address);
  void displayInfo(void);
  void describeCuisine(void);
  void addMenuItem(string name, double price);
  void displayMenu(void);
};

#endif
