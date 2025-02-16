#include <string>
using namespace std;

class MenuItem {
private:
  string name;
  double price;
public:
  MenuItem(string name, double price);
  void display(void) const;
};
