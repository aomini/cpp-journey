#include <iostream>

#ifndef PRACTICE_VECTOR
#define PRACTICE_VECTOR

namespace rk {
  static const int kMinCapacity = 16;
  static const int growthFactor = 2;
  static const int shrinkFactor = 4;

  class RVector {
    public:
      RVector(int capacity);
      ~RVector();
      // Returns the capacity of the vector
      int getSize() const;
      bool isEmpty() const;
      // Returns the capacity of the vector
      int getCapacity() const;
      // Pints pulic information about the vector
      void debugString() const;
      // Inserts value at the end of the vector
      void push(int value);
      // Gets the value in the vector at a given index
      int getValueAt(int index) const;
      // Removes value from the last
      int pop();
      // Inserts a value at given index
      void insert(int index, int value);
      // Prepends the value at the start of the vector
      void prepend(int value);
      // Deletes value at a given index
      void deleteAt(int index);
      // Removes all instances of the value in the vector
      void remove(int value);
      // Looks for value and returns the first index with that value, -1 if not found;
      int find(int value) const;

    private:
      int capacity{kMinCapacity};
      int size{0};
      std::unique_ptr<int[]> data_;
      int determineCapacity(int capacity) const;
      void resizeForSize(int candidateSize);
      void increaseSize();
      void decreaseSize();
  };
} //namespace rk
#endif

