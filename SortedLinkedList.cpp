#include "SortedLinkedList.h"
#include "ItemType.h"
#include "ListNode.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#include <exception>

using namespace std;

SortedLinkedList::SortedLinkedList(){
  head = NULL;
  currentPos = NULL;
  currLength = 0;
  currIndex = -1;
}

int SortedLinkedList::length() const{
  return currLength;
}

void SortedLinkedList::insertItem(ItemType item){
  ListNode *temp = new ListNode;
  temp -> item = item;
  if(length() == 0){
    head = temp;
    currLength++;
  }
  else if(head -> item.compareTo(item) == GREATER){
    temp -> next = head;
    head = temp;
    currLength++;
  }
  else{
    ListNode *dupl = head;
    bool duplicate = false;
    for(int i = 0; i < length(); i++){
      if(dupl -> item.compareTo(item) == EQUAL){
        duplicate = true;
      }
      dupl = dupl -> next;
    }

    if(!duplicate){
      ListNode *checker = head;
      ListNode *preChecker = NULL;
      bool endOfList = (checker != NULL);
      while(endOfList){
        if(checker -> item.compareTo(item) == LESS){
          preChecker = checker;
          checker = checker -> next;
          endOfList = (checker != NULL);
        }
        else{
          endOfList = false;
        }
      }
      temp -> next = checker;
      preChecker -> next = temp;
      currLength++;
    }
    else{
      delete temp;
      cout << "Sorry. You cannot insert the duplicate item" << endl;
    }
  }
}

void SortedLinkedList::deleteItem(ItemType item){
  ListNode *temp;
  if(length() == 0){
    cout << "You cannot delete from an empty list" << endl;
  }
  else if(searchItem(item) < 0){
  }
  else if(length() == 1){
    delete head;
    currLength--;
  }
  else if(searchItem(item) == 0){
    temp = head;
    head  = head -> next;
    delete temp;
    currLength--;
  }
  else{
    ListNode *checker = head;
    ListNode *preChecker = NULL;
    bool itemFound = (checker != NULL);
    while(itemFound){
      if(checker -> item.compareTo(item) != EQUAL){
        preChecker = checker;
        checker = checker -> next;
        itemFound = (checker != NULL);
      }
      else{
        itemFound = false;
      }
    }
    preChecker -> next = checker -> next;
    delete checker;
    currLength--;
  }
}

int SortedLinkedList::searchItem(ItemType item){
  if(length() == 0){
    cout << "List is empty" << endl;
    return -1;
  }

  int index = 0;
  ListNode *temp = head;
  while(temp != NULL){
    if(temp -> item.compareTo(item) == EQUAL){
      return index;
    }
    else{
      temp = temp -> next;
      index++;
    }
  }
  cout << "Item not found" << endl;
  return -1;
}

ItemType SortedLinkedList::getNextItem(){
  if(length() == 0){
    cout << "The list is empty" << endl;
    throw 'a';
  }
  else if(currIndex == length() - 1){
    cout << "The end of the list has been reached" << endl;
    throw 20;
  }
  else if(currentPos == NULL){
    currIndex++;
    currentPos = head;
    return currentPos -> item;
  }
  else{
    currIndex++;
    currentPos = currentPos -> next;
    return currentPos -> item;
  }
}

void SortedLinkedList::ResetList(){
  currentPos = NULL;
  currIndex = -1;
}

void SortedLinkedList::printList(){
  if(length() != 0){
    ListNode *temp = head;
    for(int i = 0; i < length(); i++){
      cout << temp -> item.getValue() << " ";
      temp = temp -> next;
    }
    cout << endl;
  }
}

SortedLinkedList::~SortedLinkedList(){
  if(length() != 0){
    ListNode *temp = NULL;
    while(head != NULL){
      temp = head;
      head = head -> next;
      delete temp;
    }
  }
  currLength = 0;
}
