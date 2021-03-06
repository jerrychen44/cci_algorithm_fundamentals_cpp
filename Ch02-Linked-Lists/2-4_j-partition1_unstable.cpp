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

/*
smaller add to head, head++ <---- input node head as a center / set head,tail ---->  lager add to tail, tail++


*/
Node * partition_unstable( Node * target_node , int x ) {

  Node *movinghead = target_node;
  Node *movingtail = target_node;

  while(target_node != nullptr){

    Node *nextNode = target_node->next;
    //if less then x, move node to the head of the existing list
    if(target_node->data < x ){

       target_node->next = movinghead;
       movinghead = target_node;

    }else{//>=x

      movingtail->next = target_node;
      movingtail = target_node;

    }
    target_node = nextNode;

  }

  movingtail->next = nullptr;


  return movinghead;
 }





int main() {
  Node * head = nullptr;
  for ( int i = 0; i < 10; ++i ) {
		insert(head, rand() % 9);
	}
  std::cout << "List before partition around 5:\n";
  printList(head);
  std::cout << "List after partition around 5:\n";
  printList(partition_unstable(head, 5));
  return 0;
}
