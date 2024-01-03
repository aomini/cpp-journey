#include <iostream>
#include "rvector.h"

using namespace std;

namespace rk {

  RVector::RVector(int cap): size(0){
    if(capacity < 1){
      cout << "Cannot make vector of that size" << endl;
      exit(EXIT_FAILURE);
    }
    int startingCapacity = determineCapacity(cap);
    capacity = startingCapacity;
    data_ = unique_ptr<int[]>(new int[startingCapacity]);
  }

  RVector::~RVector(){}
  
  int RVector::determineCapacity(int userCapacity) const{
    int actual = kMinCapacity;
    if(userCapacity >= actual){
      actual *= growthFactor;
    }
    return actual;
  }

  int RVector::getSize() const{
    return size;
  }

  int RVector::getCapacity() const {
    return RVector::capacity;
  }

  bool RVector::isEmpty() const{
    return size == 0;
  }

  void RVector::debugString() const {
    cout << "size: " << size << endl
         << "capacity" << capacity << endl
         << "items" << endl;
    for(int i = 0; i < size; i++){
      printf("%d %d", i , data_[i]);
      cout << endl;
   }
  }

  void RVector::push(int value){
    resizeForSize(size + 1);
    data_[size] = value;
    size++;
  }

  int RVector::getValueAt(int index) const {
    if(index < 0 or index >= size){
      cout << "Index out of bounds" << endl;
      exit(EXIT_FAILURE);
    }
    return data_[index];
  }

  int RVector::pop() {
    if(size == 0){
      cout << "Nothing to Pop" << endl;
      exit(EXIT_FAILURE);
    }
    resizeForSize(size - 1);
    int value = data_[size - 1];
    --size;
    return value;
  }

  void RVector::resizeForSize(int candidateSize){
    if(capacity == size){ // grow
        increaseSize(); 
    }else if(size < capacity / shrinkFactor){
      decreaseSize();
    }
  }

  void RVector::increaseSize(){
    int oldCapacity = capacity;
    int newCapacity = determineCapacity(oldCapacity + 1);
    if(oldCapacity != newCapacity){
      unique_ptr<int[]> newData(new int[newCapacity]);

      for(int i=0; i < size; i++){
        newData[i] = data_[i];
      }
      data_ = move(newData);
      capacity = newCapacity;
    }

  }

  void RVector::decreaseSize(){
    int oldCapacity = capacity;
    int newCapacity = capacity / 2;
    if(newCapacity < kMinCapacity){
      newCapacity = kMinCapacity;
    }
    if(newCapacity != oldCapacity){
      unique_ptr<int[]> newData(new int[newCapacity]);

      for(int i=0; i < size; i++){
        newData[i] = data_[i];
      }

      data_ = move(newData);
      capacity = newCapacity;
    }
  }

  void RVector::insert(int index, int value){
    if(index < 0 or index >= size){
      cout << "Index out of bound" << endl;
      exit(EXIT_FAILURE);
    }

    resizeForSize(size + 1);

    for(int i=size; i > index; i--){
      // shift elements to the right
      data_[i] = data_[i - 1];
    }

    data_[index] = value;
    size++;
  }

  void RVector::prepend(int value){
    insert(0, value);
  }

  int RVector::find(int value) const{
    int foundIndex = -1;
    for(int i=0; i < size; i++){
      if(data_[i] == value){
        foundIndex = i;
        break;
      }
    }
    return foundIndex;
  }


}


