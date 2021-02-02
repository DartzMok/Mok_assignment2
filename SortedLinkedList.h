#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "ItemType.h"
#include "ListNode.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class SortedLinkedList{
 public:
  //Default constructor
  SortedLinkedList();

  //Destructor
  ~SortedLinkedList();

  //Returns the length of the linked list
  int length() const;

  //Inserts an item intop the list while maintaing
  //ascending order of the list
  void insertItem(ItemType item);

  //Removes an item from the list
  void deleteItem(ItemType item);

  //Searches list and returns the location of the item
  //within the list
  int searchItem(ItemType item);

  //Returns the next item in the list pointed by the
  //currentPos pointer
  ItemType getNextItem();
  
  //Initializes the currentPos pointer to null
  void ResetList();

  //Prints out all items in the list
  void printList();
  
 private:
  ListNode *head;
  ListNode *currentPos;
  int currLength;
  int currIndex;
};
#endif
