#include <iostream>
#include "rvector.h"
#include "rvector.cpp"

using namespace std;
using namespace rk;

int main(){
  RVector newVector(15);

  newVector.debugString();
  
  cout << "NEW DATA:" << endl;


  for(int i =0; i < 16; i++){
    newVector.push(i);
  }

  newVector.debugString();

  newVector.push(12);
  newVector.debugString();
      

  return 0;
}
