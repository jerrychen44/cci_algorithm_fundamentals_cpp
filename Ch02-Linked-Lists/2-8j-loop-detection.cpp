/**
 *  Cracking the coding interview, edition 6
 *  Problem 2.8 Loop Detection
 *  Problem : Determine if a linkedlist has a loop. If it has a loop, find the start of loop.
 *  NOTE: I have followed the approach provided in book, however, once I find start of loop,
 *  I remove the loop. So that we can test our solution. Read comment at line 25.
 */

#include <iostream>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void found_start_of_loop_and_removeLoop( Node * loopNode, Node * head )
{
  Node * ptr1 = head;
  Node * ptr2 = loopNode;

  //Move ptr1 to head, Keep ptr2 at meeting points.
  //Each are ksteps from the Loop Start.
  //Make them move in the same pace, they must meet at the loop start
  while ( ptr1->next != ptr2->next ) {//meet at the loop start point
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  //ptr1,2 has reached start of loop, now removing the loop.
  std:: cout << "reached start of loop , ptr1 address " << ptr1->next << ", value "<< ptr1->next->data << std::endl;
  std:: cout << "reached start of loop , ptr2 address " << ptr2->next << ", value "<< ptr2->next->data << std::endl;
  //cut the loop
  ptr2->next = nullptr;
}

bool detectAndRemoveCycle( Node * head )
{
  if ( head == nullptr) {
    return false;
  }
  Node * fastPtr = head;
  Node * slowPtr = head;
  //find meeting point.
  //this will be Loop_size -k steps into the linked list
  while( slowPtr && fastPtr && fastPtr->next)
  {
    std:: cout << "Before, fastPtr address " << fastPtr << ", value "<< fastPtr->data << std::endl;
    std:: cout << "Before, slowPtr address " << slowPtr << ", value "<< slowPtr->data << std::endl;

    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;

    std:: cout << "After, fastPtr address " << fastPtr << ", value "<< fastPtr->data << std::endl;
    std:: cout << "After, slowPtr address " << slowPtr << ", value "<< slowPtr->data << std::endl;


    //Error check , no meeting point, and therefore no loop
    if(fastPtr == nullptr || fastPtr->next == nullptr){
      std:: cout << "no meeting point, and therefore no loop!" << std::endl;
      return false;
    }


    //collision found
    if ( fastPtr == slowPtr ) {
      std:: cout << "find collision, fastPtr address " << fastPtr << ", value "<< fastPtr->data << std::endl;
      std:: cout << "find collision, slowPtr address " << slowPtr << ", value "<< slowPtr->data << std::endl;

      found_start_of_loop_and_removeLoop( fastPtr, head );
      return true;
    }
  }
  return false;
}



void insert( Node * & head, int data )
{
  Node * newNode = new Node( data );
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * temp = head;
    while( temp->next != nullptr ) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void printList( Node * head )
{
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}


int main()
{
    Node * head = nullptr;
    insert( head , 1 );
    insert( head , 2 );
    insert( head , 3 );
    insert( head , 4 );
    insert( head , 5 );
    std::cout << "Current List:\n";
    printList( head );
    std::cout << "Inserting loop, connecting 5 to 2 \n";
    head->next->next->next->next->next = head->next;
    std::cout << "Detecting and deleting loop\n";
    detectAndRemoveCycle(head);
    std::cout << "Back to the same old list\n";
    printList( head );
    return 0;
}
