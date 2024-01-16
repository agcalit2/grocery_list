#ifndef GROCERYLIST_H
#define GROCERYLIST_H

#include "DynamicArray.cpp"

// Grocery item that will be used as the type for the dynamic array
struct Grocery {
  std::string name;
  double price;

  // Default constructor
  Grocery() : name(""), price(0) {}

  // Overloaded constructor
  Grocery(std::string newName, double newPrice) : name(newName), price(newPrice) {}
};

// Grocery List Class
class GroceryList {
  private:
    // Dynamic array that will hold our groceries in a private variable
    DynamicArray<Grocery> groceries;
  
  public:
    // Constructor that simply initializes the array
    GroceryList();

    // Adds an item to the array
    void addItem(Grocery item);

    // Prints the current array
    void printList();

    // Removes an item from the array
    void removeItem(size_t itemNum);
};

#endif // GROCERYLIST_H