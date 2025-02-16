#ifndef JAPANESERESTAURANT_HPP
#define JAPANESERESTAURANT_HPP

#include "Restaurant.hpp"

class JapaneseRestaurant : virtual public Restaurant {
private:
  bool hasTatami;
public:
  JapaneseRestaurant(string nme, string addr, bool tatamiAvailability);
  void describeCuisine(void);
};

#endif