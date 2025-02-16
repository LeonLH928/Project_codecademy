#include "Restaurant.hpp"
#include <iostream>
Restaurant::Restaurant(string name, string address)
  : name(name), address(address) {}

void Restaurant::displayInfo() {
  cout << this->name << " has the address of " << this->address << endl;
}

void Restaurant::describeCuisine() {
  cout << "This restaurant serves various types of cuisines." << endl;
}

void Restaurant::addMenuItem(string name, double price) {
  MenuItem item(name, price);
  menu.push_back(item);
}

void Restaurant::displayMenu() {
  cout << name << " Menu:" << endl;
  for (const MenuItem& item : menu) {
    item.display();
  }
}