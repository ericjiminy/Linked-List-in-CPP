// Eric Chun - jc2ppp - 9/12/20 - List.cpp

#include "List.h"
using namespace std;

List::List(){
  head = new ListNode();
  tail = new ListNode();
  
  head->next = tail;
  head->previous = NULL;
  tail->next = NULL;
  tail->previous = head;
  
  count = 0;
}

List::List(const List& source){
  head = new ListNode();
  tail = new ListNode();

  head->next = tail;
  tail->previous = head;

  ListItr iter(source.head->next);
  while(!iter.isPastEnd()){
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List::~List(){
  this->makeEmpty();

  delete head;
  delete tail;
}

List& List::operator=(const List& source){
  if (this == &source) {
    return *this;
  } else{
    makeEmpty();
    ListItr iter(source.head->next);
    while(!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List::isEmpty() const{
  return count == 0;
}

void List::makeEmpty(){
  if (!this->isEmpty()){
    ListItr iter(head->next);
    ListNode* currentNode;
    while (!iter.isPastEnd()) {
      currentNode = iter.current;
      iter.moveForward();
      delete currentNode;
    }

    head->next = tail;
    tail->previous = head;
  }
  count = 0;
}

ListItr List::first(){
  return ListItr(head->next);
}

ListItr List::last(){
  return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position){
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->next = position.current->next;
  newNode->previous = position.current;
  position.current->next->previous = newNode;
  position.current->next = newNode;

  count++;
}

void List::insertBefore(int x, ListItr position){
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->next = position.current;
  newNode->previous = position.current->previous;
  position.current->previous->next = newNode;
  position.current->previous = newNode;

  count++;
}

void List::insertAtTail(int x){
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->next = tail;
  newNode->previous = tail->previous;
  tail->previous->next = newNode;
  tail->previous = newNode;
  
  count++;
}

ListItr List::find(int x){
  ListItr iter(head->next);
  while (!iter.isPastEnd()){
    if (iter.retrieve() == x) return iter;
    iter.moveForward();
  }
  return iter;
}

void List::remove(int x){
  ListItr position = this->find(x);
  if (!position.isPastEnd()){
    position.current->next->previous = position.current->previous;
    position.current->previous->next = position.current->next;
    delete position.current;
    count--;
  }
}

int List::size() const{
  return count;
}
