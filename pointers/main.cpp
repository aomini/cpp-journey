#include <iostream>

using namespace std;


int main(void){ 
  // Array reference with pointer
  int newArray[2]{1,2};
  int* arrayPointer = newArray;

  cout << "Array reference with pointer: " << endl;
  for(int i=0; i < 2; i++){
    cout << *arrayPointer << endl;
    arrayPointer++; 
  }
  cout << "---------------------------------------" << endl;

  // Accessing values with pointer arithmetics on array
  int a[2];
  a[0] = 12;  
  a[1] = 14;
  cout << "Accessing values with pointer arithmetics on array";

  cout << a << ": " << *a << endl;
  cout << a + 1 << ": " << *(a+1) << endl;
  cout << a + 2 << ": " << *(a + 2) << endl;
  cout << "---------------------------------------" << endl;

  // Using pointers indexes to represent something like arrays 
  int* pointer = new int;
  pointer[0] = 24;
  pointer[1] = 12;
  pointer[2] = 345;
  for(int i =0; i < 3 ; i++){
    cout << pointer[i] << endl;
  }
  delete pointer;
  cout << "---------------------------------------" << endl;

  // Smart Pointers
  /** Smart Pointers with array */
  /** Smart pointers needs to be convenient for memory management so they do not support any pointer arithmetics */
  unique_ptr<int[]> uPointer(new int[2]);
  uPointer[0] = 1;
  uPointer[1] = 12;
  cout << "Unique Pointer " << uPointer[0] << endl;
  cout << "---------------------------------------" << endl;

  /** Smart pointers without array*/
  // unique_ptr uPointerBasic = unique_ptr<int>(new int);
  unique_ptr<int> uPointerBasic = make_unique<int>(22);
  cout << "The default value for smart pointer created is: " << *uPointerBasic << endl;
  *uPointerBasic = 1123;
  cout << "Basic Unique Pointer: " << *uPointerBasic << endl;
  cout << "---------------------------------------" << endl;

  return 0;
}

