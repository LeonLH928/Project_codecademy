#ifndef MEXICANRESTAURANT_HPP
#define MEXICANRESTAURANT_HPP

#include "Restaurant.hpp"

class MexicanRestaurant : virtual public Restaurant {
private:
  int spiceLevel;
public:
  MexicanRestaurant(string nme, string addr, int spceLevel);
  void describeCuisine(void);
};

#endif
