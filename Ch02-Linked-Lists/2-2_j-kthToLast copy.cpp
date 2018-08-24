/**
 *  Cracking the coding interview edition 6
 *  Problem 2.2
 *  Return kth to last
 *  Implement an algorithm to find the kth to last element of a singly linked list.
 *  We can assume we are not provided the length of the list.
 *
 *  Approaches:
 *  1. Iterative:
 *  	 Use two pointers
 *  	 Move first pointer k places.
 *  	 Now move second pointer(from start) and first pointer (from k+1) simultanously.
 *  	 When second pointer would have reached end, first pointer would be at kth node.
 *
 *  2. Recursive:
 *  	 Maintain an index to keep track of node.
 *  	 Solve the problem for n-1 nodes and add 1 to index.
 *  	 Since each parent call is adding 1, when counter reaches k,
 *  	 we have reached length-k node from start, which is kth node from last.
 */

#include <iostream>
#include <random>

struct Node {
  int data;
  Node * next;
  Node(int d) : data{ d }, next{ nullptr } { }
};


/**
 * Insert to the head of the list
 * @param head - Current head of list
 * @param data - new node's data
 */
void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

/**
 * [deleteList - delete the entire list]
 * @param head - head of the list
 */
void deleteList( Node * & head ) {
  Node * nextNode;
  while(head) {
    nextNode = head->next;
    delete(head);
    head = nextNode;
  }
}

/**
 * printList - Helper routine to print the list
 * @param head - Current head of the list.
 */
void printList( Node * head ) {
  while(head) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "null" << std::endl;
}

//generate a random int between min and max
/**
 * [random_range helper routine to generate a random number between min and max (including)]
 * @param  min [min of range]
 * @param  max [max of range]
 * @return     [A random number between min and max]
 */
static inline int random_range(const int min, const int max) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(mt);
}


/**
 * [kthToLastHelper - helper routine to find nth node for recursive approach
 * @param  head  - head of the list
 * @param  k     - the k value for finding kth element from last of the list.
 * @param  i     - an index maintained to keep track of current node.
 * @return       - kth node from last.
 */
Node * kthToLastHelper( Node * head, int kth , int & i) {
  if ( head == nullptr ) {
    std::cout << "head == nullptr, return " << std::endl;
    return nullptr;
  }
  //the key is we put the head->next to the kthToLastHelper()
  Node * node = kthToLastHelper(head->next, kth, i);
  i = i + 1; //add up the i from the end of list, due to recursive fun returned.
  //if we have solved problem k times from last.
  if ( i == kth ) {
    std::cout << "i == kth, return " << std::endl;

    return head;
  }
  // if we don't found the kth in original string, node = nullptr
  std::cout << "return " << std::endl;
  return node;
}

/**
 * kthToLastRecursive - Recursive approach for finding kth to last element of list.
 * @param  head  - head of node
 * @param  k     - the k value for finding kth element from last of the list.
 * @return       - kth node from last.
 */
Node * kthToLastRecursive( Node * head, int kth ) {
  int i = 0;
  return kthToLastHelper(head, kth, i);
}

/**
 * kthToLastIterative -  Iterative approach for finding kth to last element of list.
 * @param  head  - head of node
 * @param  k     - the k value for finding kth element from last of the list.
 * @return       - kth node from last.
 */
Node * kthToLastIterative( Node * head, int kth ) {
  if ( head == nullptr ) {
    return head;
  }

  Node * ptr1 = head;
  Node * ptr2 = head;

  int i = 0;
  while( i < kth && ptr1 ) {
    ptr1 = ptr1->next;//keep move to next list node
    ++i;
  }

  //out of bounds
  if ( i < kth ) {
    return nullptr;
  }

  while( ptr1 != nullptr ) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  return ptr2;
}



int main() {

  Node * head = nullptr;

  for ( int i = 7; i > 0; i-- ) {
    insert(head, random_range(1,100));
  }
  std::cout << "List: ";
  printList(head);

  std::cout << "4th node from last (Recursive) : ";
  Node *node4 = kthToLastRecursive(head, 4);
  if ( node4 != nullptr ) {
    std::cout << node4->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }


  std::cout << "4th node from last (Iterative) : ";
  node4 = kthToLastIterative(head, 4);
  if ( node4 != nullptr ) {
    std::cout << node4->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }


  deleteList(head);

  return 0;
}
