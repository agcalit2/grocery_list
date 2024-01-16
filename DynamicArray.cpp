#include "DynamicArray.h"
#include <iostream>

// our default constructor
template <typename T>
DynamicArray<T>::DynamicArray() : mySize(0), maxSize(DEFAULT_SIZE), myVals(new T[DEFAULT_SIZE]) {}

// our destructor
template <typename T>
DynamicArray<T>::~DynamicArray() {
  myVals = nullptr;
  mySize = 0;
}

// adds a value to the next available spot in the array
template <typename T>
void DynamicArray<T>::addVal(T val) {
  // doubles in size, dynamically, if we're out of space. creates a new array and swaps the values
  if (mySize == maxSize) {
    T* temp = new T[maxSize * 2];
    // loads in the new vals
    for (size_t i = 0; i < maxSize; ++i) {
      temp[i] = myVals[i];
    }
    // swap changes the pointers from temp to myVals
    std::swap(myVals, temp); 
    maxSize *= 2;
    delete[] temp;
  }
  myVals[mySize] = val;
  mySize++;
}

// print out all the values that we are holding on to right now
template <typename T>
void DynamicArray<T>::printVals() {
  for (size_t i = 0; i < mySize; ++i) {
    std::cout << "Item Number: " << i + 1 << std::endl;
    std::cout << " Name: " << myVals[i].name << std::endl;
    std::cout << " Price: " << myVals[i].price << std::endl;
  }
}

// access and prints out a specific value at an index, given that it's within our current bounds
template <typename T>
T DynamicArray<T>::accessVal(size_t index) {
  if (index < mySize) {
    return myVals[index];
  } else {
    throw std::out_of_range("Index out of bounds");
  }
}

// Returns the current size of the dynamic array
template <typename T>
size_t DynamicArray<T>::getSize() {
  return mySize;
}