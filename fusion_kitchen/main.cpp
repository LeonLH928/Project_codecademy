#include <iostream>
#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"
#include "MexicanJapaneseFusion.hpp"

using namespace std;

int main() {
    cout << "Testing Restaurant Inheritance Hierarchy:" << endl;
    MexicanRestaurant mex("La Casa", "123 Spice Lane", 4);
    JapaneseRestaurant jap("Sakura", "456 Sushi Road", true);
    MexicanJapaneseFusion fus("Fusion Fiesta", "789 Fusion Ave", 3, true);
    mex.displayInfo();
    mex.describeCuisine();
    jap.displayInfo();
    jap.describeCuisine();
    fus.MexicanRestaurant::displayInfo();
    fus.MexicanRestaurant::describeCuisine();
    fus.JapaneseRestaurant::displayInfo();
    fus.JapaneseRestaurant::describeCuisine();
    
    mex.addMenuItem("Tacos", 8.99);
    mex.addMenuItem("Enchiladas", 12.99);
    jap.addMenuItem("Sushi Roll", 14.99);
    jap.addMenuItem("Ramen", 11.99);
    fus.addMenuItem("Sushi Tacos", 15.99);
    fus.addMenuItem("Wasabi Guacamole", 7.99);
    
    mex.displayMenu();
    jap.displayMenu();
    fus.displayMenu();
    
    return 0;
}
