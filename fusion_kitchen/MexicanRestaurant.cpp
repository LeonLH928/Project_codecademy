#include "MexicanRestaurant.hpp"
#include <iostream>
MexicanRestaurant::MexicanRestaurant(string nme, string addr, int spceLevel) : Restaurant(nme, addr), spiceLevel(spceLevel) {}

void MexicanRestaurant::describeCuisine() {
  cout << "Authentic Mexican cuisine with spice level " << this->spiceLevel << " out of 5" << endl;
}