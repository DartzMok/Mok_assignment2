#include "ItemType.h"
#include "SortedLinkedList.h"
#include "ListNode.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){
  SortedLinkedList list;
  ItemType item;
  int input;
  fstream fs;
  bool run = true;
  char user;
  
  fs.open(argv[1], fstream::in);
  if(fs.is_open()){
    fs >> input;
    while(!fs.eof()){
      item.initialize(input);
      list.insertItem(item);
      fs >> input;
    }
  }
  else{
    cout << "Failed to open the input file" << endl;
    return 0;
  }
  fs.close();

  cout << endl;
  
  while(run){
    cout << "Commands:" << endl;
    cout << "(i) - Insert value" << endl;
    cout << "(d) - Delete value" << endl;
    cout << "(s) - Search value" << endl;
    cout << "(n) - Print next iterator value" << endl;
    cout << "(r) - Reset iterator" << endl;
    cout << "(p) - Print list" << endl;
    cout << "(l) - Print length" << endl;
    cout << "(q) - Quit program" << endl;

    cout << "Enter a command: ";
    cin >> user;
    cin.clear(); fflush(stdin);
    if(user == 'i'){
      int num;
      cout << "Enter a number: ";
      cin >> num;
      cin.clear(); fflush(stdin);
      cout << endl;
      item.initialize(num);
      list.insertItem(item);
      list.printList(); cout << endl;
    }
    else if(user == 'd'){
      int num;
      cout << "Enter value to delete: ";
      cin >> num;
      cin.clear(); fflush(stdin);
      cout << endl;
      item.initialize(num);
      list.deleteItem(item);
      list.printList(); cout << endl;
    }
    else if(user == 's'){
      int num;
      cout << "Enter a value to search: ";
      cin >> num;
      cin.clear(); fflush(stdin);
      cout << endl;

      item.initialize(num);
      int result = list.searchItem(item);
      if(result >= 0){
        cout << "Index " << result << endl;
      }
    }
    else if(user == 'n'){
      cout << endl;          
      try{
        cout << list.getNextItem().getValue() << endl;
      }
      catch(char a){
      }
      catch(int num){
      }
      cout << endl;
    }
    else if(user == 'r'){
      cout << endl;
      list.ResetList();
      cout << "Iterator reset." << endl;
      cout << endl;
    }
    else if(user == 'p'){
      cout << endl;
      list.printList();
      cout << endl;
    }
    else if(user == 'l'){
      cout << endl;
      cout << "List Length is " << list.length() << endl;
      cout << endl;
    }
    else if(user == 'q'){
      cout << "Quitting program..." << endl;
      run = false;
    }
    else{
      cout << "Invalid command, try again!" << endl;
    }
  }
  return 0;
}
