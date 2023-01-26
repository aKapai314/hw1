/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  //Node*& in is the inputted list head
  //Node*& odds is the head of a list of odds which starts out at NULL
  //Node*& evens is the head of a list of evens which starts out as NULL
  if(in != NULL){ //if the list is non-empty
    if(in->next != NULL){ //if the list is greater than one node
      //split the rest of the list
      Node* new_in = in->next; 
      split(new_in, odds, evens);
    }
    //if the current node is even including zero, add it to the evens
    if( (in->value) % 2 == 0){
      in->next = evens;
      evens = in;
      in = NULL;
    }
    //if the current node is odd, add it to the odds
    else{
      in->next = odds;
      odds = in;
      in = NULL;
    }
  }
}
