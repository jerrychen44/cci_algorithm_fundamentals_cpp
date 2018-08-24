/*
 * Cracking the coding interview edition 6
 * Problem 2-1 : Remove duplicates from an unsorted linked list.
 * Approach 1 : Naive approach of iterating and remove all further duplicates of current node.
 * 							Space complexity O(1) & time complexity O(n^2)
 * Approach 2: Use a hash table, space complexity O(n), time complexity O(n)
 */


#include <iostream>
#include <unordered_map>
#include <random>



struct Node{
	Node *next = nullptr;
	int data = 0;
};

/**
 * [insert - insert a node at the head of list]
 * @param head [head of the list]
 * @param data [new node's data]
 */
void insert_to_first( Node * & head, int data )
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

/**
 * [printList Helper routine to print list]
 * @param head [head of the list]
 */
void printList( Node * head ) {
	while( head ) {
		std::cout << head->data << "-->";
		head = head->next;
	}
	std::cout << "nullptr" << std::endl;
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


// Method 1
//space complexity O(1)
// time complexity O(n^2), n + (n-1) + (n-2) + .....+ 1 = n(n-1)/2 = O(n^2)
/**
 * [removeDuplicates Remove duplicates without using extra space]
 * @param head [head of list]
 */
void removeDuplicates1( Node * head ) {
	if ( head == nullptr || ( head && (head->next == nullptr))) {
		return;
	}
	Node * curr = head;

	//its kind of the double for loop i, j = i for linklist
	//if curr not nullptr
	while(curr) {
		Node * runner = curr;

		while (runner->next != nullptr) {
			//next data equal curr data
			if (runner->next->data == curr->data) {
				//we skip next node
				runner->next = runner->next->next;
			} else {
				//runner set as next node
				runner = runner->next;
			}
		}
		curr = curr->next;
	}
}

// Method 2
// space complexity - O(n), n is the number of linklist elemnet
// time complexity - O(n)
/**
 * [removeDuplicates1 - Remove duplicates from the list using hash table]
 * @param head [head of list]
 */
void removeDuplicates2( Node * head ) {
	if ( head == nullptr || ( head && (head->next == nullptr) )) {
		return ;
	}

	std::unordered_map<int, int> node_map; //hash table as a map
	Node * prev = head;
	Node * curr = head->next;
	node_map[head->data] = 1;

	while( curr != nullptr ) {
		while (curr && node_map.find(curr->data) != node_map.end()) {
			//if we find curr data, and not found it at the end
			//we kip the curr node, which means move curr to next
			curr = curr->next;
		}
		//update the curr to prev->next
		prev->next = curr;

		//prepare for next round, just like at first beginning, prev = head, curr = head->next
		prev = curr;
		//set the curr data to 1, and move to next
		if (curr) {
			node_map[curr->data] = 1;
			curr = curr->next;
		}
	}
}



int main() {
	std::cout << "Method 1 : \n";
	Node * head = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		insert_to_first(head, random_range(1,7));
	}
	printList(head);
	removeDuplicates1(head);
	printList(head);


	std::cout << "Method 2 : \n";
	Node * head1 = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		insert_to_first(head1, random_range(1,7));
	}
	printList(head1);
	removeDuplicates2(head1);
	printList(head1);

	return 0;
}
