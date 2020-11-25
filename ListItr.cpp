// Eric Chun - jc2ppp - 9/12/20 - ListItr.cpp

#include <iostream>
#include "ListItr.h"
using namespace std;

ListItr::ListItr(){
  current = NULL;
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

bool ListItr::isPastEnd() const{
  return current->next == NULL;
}

bool ListItr::isPastBeginning() const{
  return current->previous == NULL;
}

void ListItr::moveForward(){
  if (!this->isPastEnd()) current = current->next;
}

void ListItr::moveBackward(){
  if (!this->isPastBeginning()) current = current->previous;
}

int ListItr::retrieve() const{
  return current->value;
}

void printList(List& source, bool forward){
  if (forward){
    ListItr itr = source.first();
    while (!itr.isPastEnd()){
      cout << itr.retrieve() << ' ';
      itr.moveForward();
    }
    cout << endl;
  } else{
    ListItr itr = source.last();
    while (!itr.isPastBeginning()){
      cout << itr.retrieve() << ' ';
      itr.moveBackward();
    }
    cout << endl;
  }
}
