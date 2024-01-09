#include "linked_list.h"
#include <iostream>

using namespace std;

namespace RLinkedList {
  
  /** Clear Space */
  LinkedList::~LinkedList(){
    cout << "Linked List Destroyed";
  }

  int LinkedList::size() const{
    int size = 0;
    auto current = head;
    while(current != nullptr){
      size++;
      current = current->next;
    }
    return size;
  }


  bool LinkedList::empty() const{
    return head == nullptr;
  }

  void LinkedList::printDebugString() const {
    cout << "DEBUG STRING: \n" << endl;
    cout << "Size is: " << size() << "\n" << endl;

    cout << "ELEMENTS: " << endl;
    auto current = head;
    int i = 0;
    while(current != nullptr){
      printf("Index %d -> %d \n", i, current->value);
      current = current->next; 
      i++;
    }
  }


  void LinkedList::pushFront(int value){
    struct node* temp = new struct node;
    temp->value = value;
    temp->next = head;
    head = temp;
  }

  void LinkedList::pushBack(int value){
    if(empty()){
      pushFront(value);
    }else{
      struct node* node = new struct node;
      node->value = value;

      auto *current = head;

      while(current->next){
        current = current->next;
      }
      node->next = current->next;
      current->next = node;
    }
  }

  int LinkedList::front() const{
    if(empty()){
      cerr << "List is empty" << endl;
      exit(EXIT_FAILURE);
    }
    return head->value;
  }

  int LinkedList::back() const {
    if(empty()){
      cerr << "List is empty" << endl;
      exit(EXIT_FAILURE);
    }
    auto *current = head;
    while(current->next){
      current = current->next;
    }
  
    return current->value;
  }

  int LinkedList::valueAt(int index) const {
    auto *current = head;
    if(empty()){
      cerr << "List is empty" << endl;
      exit(EXIT_FAILURE);
    }

    if(index < 0){
      cerr << "Index should always be greater than -1" << endl;
      exit(EXIT_FAILURE);
    }

    for(int i = 0; i < index && current != nullptr; i++){
      current = current->next; 
    }

    if(current == nullptr){
      cerr << "Index out of bounds" << endl;
      exit(EXIT_FAILURE);
    }
    return current->value;
  }


  int LinkedList::valueFromEnd(int n) const {
    if(empty()){
      cerr << "List is empty" << endl;
      exit(EXIT_FAILURE);
    }

    if(n < 0){
      cerr << "Index should always be greater than -1" << endl;
      exit(EXIT_FAILURE);
    }

    int index = size() - 1 - n;
    return valueAt(index);
  }

  int LinkedList::popFront(){
    if(empty()){
      cerr << "Nothing to pop, list is empty" << endl;
      exit(EXIT_FAILURE);
    }
    auto *node = head;
    int value = node->value;
    head = head->next;
    delete node;
    return value;
  }

  int LinkedList::popBack(){
    if(empty()){
      cerr << "Nothing to pop, list is empty" << endl;
      exit(EXIT_FAILURE);
    }
    auto *current = head;
    while(current->next){
      if(current->next->next){
        current = current->next;
      }else{
        break;
      }
    }
    
    if(current->next == nullptr){
      int value = current->value;
      head = nullptr;
      delete current;
      return value;
    } else{
        int lastValue = back();
        delete current->next->next;
        current->next = nullptr;
        return lastValue;
    }
  }

  /** No need to free Pointer space since it's addition not a removal */
  void LinkedList::insert(int index, int value) {
    if(empty()){
      cerr << "The List is empty" << endl;
      exit(EXIT_FAILURE);
    }

    auto* current = head;
    if(index == 0){
      struct node* node = new struct node;
      node->value = value;
      node->next = head;
      head = node;
    }else{
      for(int i = 0; i < (index-1) && current != nullptr; i++){
        current = current->next;
      }
      if(current == nullptr){
        cerr << "Index Out of Bounds" << endl;
        exit(EXIT_FAILURE);
      }
      struct node* node = new struct node;
      node->value = value;
      node->next = current->next;
      current->next = node;
    }
  }

  void LinkedList::reverse(){
      struct node* current = head;
      struct node* previous = nullptr;
      struct node* next = nullptr;
      while(current != nullptr){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
      }
      head = previous;
  }

  /** Implementation Remained */
  void LinkedList::erase(int index){
    if(empty()){
      cerr << "Nothing to pop, list is empty" << endl;
      exit(EXIT_FAILURE);
    }
     
  }

}
void printLine(){
  cout << "---------------------------------------------" << endl;
}

int main(){
  /** Linked List */
  cout << "LINKED LISTS" << endl;
  printLine();

  auto ll = new RLinkedList::LinkedList();
  ll->pushFront(12);
  ll->pushBack(13);
  ll->pushFront(11);
  ll->pushBack(14);
  ll->printDebugString();

  ll->insert(0, 99);

  ll->printDebugString();
  ll->reverse();
  cout << "AFTER REVERSE: " << endl;
  ll->printDebugString();
  /* cout << "First element inserted is: " << ll->head->value << endl; */
  printLine();

}





