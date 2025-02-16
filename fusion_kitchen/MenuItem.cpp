#include "MenuItem.hpp"
#include <iostream>
MenuItem::MenuItem(string name, double price) : name(name), price(price) {}

void MenuItem::display() const {
  cout << name << " - $" << price << endl;
}