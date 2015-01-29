#include <iostream>
#include <vector>
using namespace std;

const int DEEP_DISH = 1;
const int HAND_TOSSED = 2;
const int PAN = 3;

const char SMALL = 's';
const char MEDIUM = 'm';
const char LARGE = 'l';

class Pizza {
  public:
    Pizza();
    Pizza(int pizzaTypeSpec, char pizzaSizeSpec);
    Pizza(int pizzaTypeSpec, char pizzaSizeSpec, 
          int pepperoniNumber, int cheeseValue);
    // Mutator functions
    void setPizzaType();
    void setPizzaSize();
    void setPepperoniNumber();
    void setCheeseNumber();

    // Accessor functions
    int getPizzaType();
    char getPizzaSize();
    int getPepperoniNumber();
    int getCheeseNumber();

    // Output a textual description of the pizza object
    void outputDescription();     
    // Compute the cost of the pizza and return it as a double:
    // Small pizza = $10 + $2 per topping
    // Medium pizza = $14 + $2 per topping
    // Large pizza = $17 + $2 per topping
    double computePrice();
  private:
    int pizzaType;
    char pizzaSize; 
    int pepperoni;
    int cheese;
};

/*
class Order
include appropriate functions so that a user of the order class can add pizzas to the order
write a function that outputs everything in the order along with the total price.
*/

class Order {
  public:
    void setOrder();
    void outputOrder();  
  private:
    vector<Pizza> order;
    double totalPrice;
    void computeTotalPrice();
};

int main() {
  Order order;
  order.setOrder();
  order.outputOrder();
  
  return 0;
}    

Pizza::Pizza() : pizzaType(DEEP_DISH), pizzaSize(MEDIUM), 
                 pepperoni(0), cheese(0) {};
Pizza::Pizza(int pizzaTypeSpec, char pizzaSizeSpec) 
              : pizzaType(pizzaTypeSpec), pizzaSize(pizzaSizeSpec), 
                pepperoni(0), cheese(0) {};

Pizza::Pizza(int pizzaTypeSpec, char pizzaSizeSpec, 
             int pepperoniNumber, int cheeseValue) 
              : pizzaType(pizzaTypeSpec), pizzaSize(pizzaSizeSpec), 
                pepperoni(pepperoniNumber), cheese(cheeseValue) {};


void Pizza::setPizzaType() {
  cout << "Choose a pizza type: deep dish = 1, hand tossed = 2 or pan = 3: ";
  cin >> pizzaType;
}
void Pizza::setPizzaSize() {
  cout << "Choose a pizza size: small = s, medium = m or large = l: ";
  cin >> pizzaSize;
}
void Pizza::setPepperoniNumber() {
  cout << "How many pepperoni do you want? ";
  cin >> pepperoni;
}
void Pizza::setCheeseNumber() {
  cout << "How many cheeses do you want? ";
  cin >> cheese;
}


int Pizza::getPizzaType() {
  return pizzaType;
}
char Pizza::getPizzaSize() {
  return pizzaSize;
}
int Pizza::getPepperoniNumber() {
  return pepperoni;
}
int Pizza::getCheeseNumber() {
  return cheese;
}

// Output a textual description of the pizza object
void Pizza::outputDescription() {
  cout << "\t***Pizza type: ";
  switch(pizzaType) {
    case DEEP_DISH:
      cout << "Deep dish"; break;
    case HAND_TOSSED:
      cout << "Hand tossed"; break;
    case PAN:
      cout << "Pan"; break;
    default:
      cerr << "Invalid pizza type.\n";
      exit(1);
  }
  cout << ", size: ";
  switch(pizzaSize) {
    case SMALL:
      cout << "small"; break;
    case MEDIUM:
      cout << "medium"; break;
    case LARGE:
      cout << "large"; break;
    default:
      cerr << "Invalid pizza size.\n";
      exit(1);
  }
  cout << ", with " << pepperoni << " pepperoni and " << cheese << " cheeses."
       << "***" << endl;
}

// Compute the cost of the pizza and return it as a double:
double Pizza::computePrice() {
  switch(pizzaSize) {
    case SMALL:
      return (10 + 2 * (pepperoni + cheese)); break;
    case MEDIUM:
      return (14 + 2 * (pepperoni + cheese)); break;
    case LARGE:
      return (17 + 2 * (pepperoni + cheese)); break;
    default:
      cerr << "Invalid pizza size.\n";
      exit(1);
  }
}

void Order::setOrder() {
  Pizza pizza;
  char answer = ' ';
  cout << "Make your order:\n";
  do {
    pizza.setPizzaType();
    pizza.setPizzaSize();
    pizza.setPepperoniNumber();
    pizza.setCheeseNumber();
    order.push_back(pizza);
  
    cout << "Do you want to order another pizza? Yes (Y/y) or No (N/n)? ";
    cin >> answer;
  } while(answer == 'Y' || answer == 'y');
}
void Order::outputOrder() {
  cout << "You ordered:\n";
  for (int i = 0; i < order.size(); i++) {
    order[i].outputDescription();     
    cout << "\t Price: " << order[i].computePrice() << endl;
  }
  cout << endl;
  computeTotalPrice();
}

void Order::computeTotalPrice() {
  for (int i = 0; i < order.size(); i++) {
    totalPrice += order[i].computePrice();
  }
  cout << "Total price: $" << totalPrice << endl;
}
