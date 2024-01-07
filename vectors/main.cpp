#include <iostream>
#include <vector>

using namespace std;


/* void printVector(char[] message, int value){ */
/*   cout << message << " " << value << endl; */
/* } */

int main(){
  vector<int> hello{};

  hello.push_back(12);
  hello.push_back(15);

  cout << "Looping with auto for loop: " << endl;
  for(auto element: hello){
    cout << element << endl;
  }
  hello.clear();


  /* Iterators */ 
  hello.insert(hello.begin(), 1);
  hello.insert(hello.begin() + 1, 2);
  hello.insert(hello.end(), 12);
  cout << "Looping with iterators" << endl;
  for(vector<int>::iterator i = hello.begin(); i != hello.end(); i++){
    cout << *i << endl;
  }
  cout << "Printing last element with iterator: " << *(hello.end() - 1) << endl;

  /** Removing an element from an iterator */
  hello.erase(hello.begin());
  cout << "Print first element after removal: " << *hello.begin() << endl;

  /** Find an element */
  


  /** Finding element with Iterators */





  /* for(const int& i: vector){ */ /*   cout << i << " "; */ /* } */ // Add  elements
  
  // insert & emplace
  //
  //
  // add elements
  // chanage elements
  // Remove Elements

  // Check with iterators looping
  // cout << *hello.begin() << endl;



} 


