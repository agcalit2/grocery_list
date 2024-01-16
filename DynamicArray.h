#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdio.h>
#include <string>

const size_t DEFAULT_SIZE = 5;

template <typename T>
class DynamicArray {

  private:
    size_t mySize; // this keeps track of our current size
    size_t maxSize; // this is the capacity of our array
    T *myVals; // keeps track of the values in a Grocery array

  public:
    // default constructor
    DynamicArray();   
 
    // the destructor
    ~DynamicArray();  

    // adds a value to the current location in the dynamic array
    void addVal(T val);

    // print out the current vals in the array
    void printVals();

    // access and prints out a specific value at an index, given that it's within our current bounds
    T accessVal(size_t index);

    // Gets the current size of the array
    size_t getSize();
};

#endif // DYNAMICARRAY_H