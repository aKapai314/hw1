#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
using namespace std;
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0; //number of strings stored in the entire list
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* temp = head_;
  size_t itemCount = 0;
  int index = -1;
  int location = loc;
  size_t i;
  
  if(size_ == 1)
    return &(temp->val[temp->first + loc]);
  while(temp != NULL){
    for(i = 0; i < ARRSIZE; i++){
      if(temp->val[i] != ""){
        index++;
      }
      if(index >= location)
        break;
    }
    if(index >= location)
      break;
    itemCount ++;
    temp = temp->next;
  }

  if(index > -1)
    return &(temp->val[i]);

  return NULL;
}

void ULListStr::push_back(const std::string& str){
  if(size_ == 0){ //if list is empty
    Item* curr = new Item; //allocate new Item
    head_ = curr; //update head
    tail_ = curr; //update tail
    //Item prev and next stay at NULL
    curr->last = 1; //update last to point 1 after element
    curr->val[0] = str; //copy string into beginning element
    size_++; //update size of list
  } 
  else if(tail_->last == ARRSIZE){ //if(tail_->last != ARRSIZE) 
    //if the last array element of the last Item is full
    Item* curr = new Item; //allocate new Item
    tail_->next = curr; // update prev Item's next
    curr->prev = tail_; //update curr Item's prev
    tail_ = curr; //update tail
    //Item next stays at NULL
    curr->val[0] = str; //copy string into first element of array
    curr->last = 1; //update last to point 1 after element 
    size_++; //update size of List
  }
  else{ //if there is enough space to place the new string
    tail_->val[tail_->last] = str; //copy string into first empty element of array
    (tail_->last)++; //update last to point 1 after new element
    size_++; //update size of list
  }
}

void ULListStr::pop_back(){
if(size_ == 0)
    return;
if(tail_->last == 1 || size_ == 1){ //if there's only one element left in an item
    Item* temp = tail_->prev; 
    delete tail_;
    tail_ = temp; //delete and update tail
    if(tail_ != NULL)
      tail_->next = NULL;
    else  
      head_ = NULL;
    size_--; //update size
  }
  else{ //if there is more than one element left in an item
    tail_->val[tail_->last - 1] = ""; //remove that element
    (tail_->last)--; //update first
    size_--; //update size
  }
}

void ULListStr::push_front(const std::string& str){
if(size_ == 0){ //if list is empty
    Item* curr = new Item; //allocate new Item
    head_ = curr; //update head
    tail_ = curr; //update tail
    //Item prev and next stay at NULL
    curr->last = ARRSIZE; //update last to point 1 after element
    curr->val[ARRSIZE-1] = str; //copy string into beginning element
    curr->first = ARRSIZE-1;
    size_++; //update size of list
  } 
  else if(head_->first == 0){//if there is not enough space to place the new string
    Item* curr = new Item; //allocate new Item
    curr->next = head_; //update Item's next
    head_->prev = curr;
    //Item prev stays at NULL
    head_ = curr; //update head
    curr->val[ARRSIZE-1] = str; //copy string into last element of array
    curr->last = ARRSIZE; //update last to point 1 after element 
    curr->first = ARRSIZE-1;
    size_++; //update size of List
  }
  else{  //if there is  space for a new string to be added at the front
    head_->val[(head_->first) - 1] = str;
    (head_->first)--;
    size_++;
  } 
}

void ULListStr::pop_front(){
  if(size_ == 0)
    return;
  if(head_->first == ARRSIZE - 1 || size_ == 1){ //if there's only one element left in an item
    Item* temp = head_->next;
    delete head_;
    head_ = temp; //delete and update head
    if(head_ != NULL)
      head_->prev = NULL;
    size_--; //update size
  }
  else{ //if there is more than one element left in an item
    head_->val[head_->first] = ""; //remove that element
    (head_->first)++; //update first
    size_--; //update size
  }
}
 
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}
  
 