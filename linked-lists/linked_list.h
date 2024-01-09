
#ifndef PROJECT_LINKED_LIST
#define PROJECT_LINKED_LIST


namespace RLinkedList{
  struct node{
    int value;
    struct node *next;
  };

  class LinkedList{
    public:
      LinkedList(): head(nullptr){};
      ~LinkedList();
      int size() const;

      /** Returns true if the list is empty */
      bool empty() const; 

      /** Void debug string */
      void printDebugString() const;

      /* Push value at the front of the list */ 
      void pushFront(int value);

      /** Push value at the back of the list */
      void pushBack(int value);

      /** Get front value */
      int front() const;

      /** Get back value */
      int back() const;

      /** Returns value at nth position given index starts at 0 */
      int valueAt(int index) const;

      /** Returns the value of a node at nth position from the end of the list*/
      int valueFromEnd(int n) const;

      /** Remove value from the front */
      int popFront();

      /** Remove value from the front */
      int popBack();

      /** Insert value at a position (index position) in the list */
      void insert(int index, int value);

      /** Find the index of a value return null if none found */
      struct node find(int value);

      /** Removes value at a given index */
      void erase(int index);

      /** Reverse the items stored in the list */
      void reverse();

    private:
      struct node* head;
  };
}

#endif
