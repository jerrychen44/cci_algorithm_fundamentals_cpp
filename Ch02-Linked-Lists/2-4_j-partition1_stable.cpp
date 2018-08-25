/**
 *  Cracking the coding interview edition 6
 *  Problem 2.4 Partition:
 *  Write code to partition linked list around a value x, such that
 *  nodes less than x come before all the nodes greater than or equal to x.
 *  If x is in the list, the values of x only need to be after the elements less
 *  than x.
 *  Example
 *  3-->5-->8-->5-->10-->2-->1 (x = 5)
 *  3-->1-->2-->10-->5-->5-->8
 *
 *  Approach:
 *  Start with first node, and add every thing bigger or equal to x at tail
 *  and smaller values at head.
 */

#include <iostream>
#include <random>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * curr = head;
    while( curr->next ) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

void printList( Node * head ) {
  while ( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}


 /* We start with two new list.
 Elements bigger than the pivot element are put at the tail list
 and elements smaller are put at the head list*/

Node * partition( Node * input_listhead , int x ) {

   //create two new list
   Node * head = nullptr;
   Node * headInitial = nullptr;   /*The initial node of list head*/
   Node * tail = nullptr;
   Node * tailInitial = nullptr;   /*The initial node of list tail*/

   //current index
   Node * curr = input_listhead;


   while( curr != nullptr ) {
    //get the next node first
     Node * nextNode = curr->next;
     if ( curr->data < x ) {
            // we put node to head list first time
            if (head == nullptr) {
                head = curr;
                headInitial = head;//we will not move headInitial
            }
       //insert curr node to head list
       head->next = curr;
       //update head
       head = curr;
     } else {
            if (tail == nullptr) {
                tail = curr;
                tailInitial = tail;
            }
       // insert curr node to tail list
       tail->next = curr;
       tail = curr;
     }
     //update the curr for next round
     curr = nextNode;
   }
   //concate tail to headlist as a result
   head->next = tailInitial;  /*Now, we connect the head list to tail list.*/
   tail->next = nullptr;
   return headInitial;
 }





int main() {
  Node * head = nullptr;
  for ( int i = 0; i < 10; ++i ) {
		insert(head, rand() % 20);
	}
  std::cout << "List before partition around 5:\n";
  printList(head);
  std::cout << "List after partition around 5:\n";
  printList(partition(head, 5));
  return 0;
}
