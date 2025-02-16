#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"

class MexicanJapaneseFusion : public MexicanRestaurant, public JapaneseRestaurant {
public:
  MexicanJapaneseFusion(string name, string addr, int spiceLvl, bool tatamiAvail);
  void describeCuisine(void);
  void displaySpecialty(void);
};
