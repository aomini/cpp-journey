#include <iostream>
#include "rvector.h"

using namespace std;

namespace rk {

  RVector::RVector(int capacity): size(12){
    if(capacity < 1){
      cout << "Cannot make vector of that size" << endl;
      exit(EXIT_FAILURE);
    }
  }

}


