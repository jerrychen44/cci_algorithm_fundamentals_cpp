#include "j_Stack.h"

Stack::Stack()
{
  head = nullptr;
  stackSize = 0;
}

Stack::~Stack()
{
  StackNode *discard;
  //delete all nodes
  while(head != nullptr)
  {
    discard = head;
    head = head->next;
    delete discard;
  }
}
//O(1)
void Stack::push(int item)
{
  if(isEmpty())
  { //is the stack is empty, push the first item
    head = new StackNode(item, nullptr);
    head->minimum = head;
  }
  else if(item <= head->minimum->data)
  {
    head = new StackNode(item, head);
    head->minimum = head;
  }
  else
  {
    head = new StackNode(item, head);
    head->minimum = head->next->minimum;
  }

  stackSize++;
}
//pop head
//O(1)
void Stack::pop()
{
  if(stackSize == 0 || head == nullptr)
    return;

  StackNode *discard = head;
  head = head->next;
  delete discard;
  stackSize--;
}
//O(1)
int Stack::top() const
{
  //Or throw an exception
  if(stackSize == 0 || head == nullptr)
  {
    std::cout << "Stack is empty.\n";
    exit(1);
  }
  return head->data;
}
//O(1)
int Stack::getMinimum() const
{
  //Or throw an exception
  if(stackSize == 0 || head == nullptr)
  {
    std::cout << "Stack is empty.\n";
    exit(1);
  }
  return (head->minimum->data);
}

bool Stack::isEmpty() const
{
  return (stackSize == 0 || head == nullptr);
}

int Stack::getSize() const
{
  return stackSize;
}

int main(){

  Stack mystack = Stack();
  std::cout << "stack size " << mystack.getSize() << std::endl;

  mystack.push(11);
  mystack.push(22);
  mystack.push(33);
  mystack.push(44);
  mystack.push(55);

  std::cout << "stack size " << mystack.getSize() << std::endl;
  std::cout << "stack top " << mystack.top() << std::endl;
  std::cout << "stack getMinimum " << mystack.getMinimum() << std::endl;


  return 0;
}
