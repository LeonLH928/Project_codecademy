#include "JapaneseRestaurant.hpp"
#include <iostream>
JapaneseRestaurant::JapaneseRestaurant(string nme, string addr, bool tatamiAvailability) : Restaurant(nme, addr), hasTatami(tatamiAvailability) {}

void JapaneseRestaurant::describeCuisine() {
  if (hasTatami) {
    cout << "Traditional Japanese cuisine with tatami seating available" << endl;
  } else {
    cout << "Traditional Japanese cuisine" << endl;
  }
}