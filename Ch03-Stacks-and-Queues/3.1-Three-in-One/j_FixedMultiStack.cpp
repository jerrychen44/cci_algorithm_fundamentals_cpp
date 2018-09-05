#include "FixedMultiStack.h"

FixedMultiStack::FixedMultiStack(int stackCapacity)
{
  this->stackCapacity = stackCapacity;
  //Default initialization in C++ use ()
  stackArray = new int[numOfStack * stackCapacity]();
  stackCapacityUsed = new int[numOfStack]();
}

FixedMultiStack::~FixedMultiStack()
{
  delete [] stackArray;
  delete [] stackCapacityUsed;
}

void FixedMultiStack::push(int stackNum, int value)
{
  if(isFull(stackNum))
    std::cout << "Stack " << stackNum << " is full.\n";
  else
  {
    stackCapacityUsed[stackNum]++;
    stackArray[indexOfTop(stackNum)] = value;
    std::cout << "Test" << std::endl;

  }
}

int FixedMultiStack::pop(int stackNum)
{
  int popout=0;
  if(isEmpty(stackNum)){
    std::cout << "Stack " << stackNum << " is empty.\n";
    popout = -1;
  }
  else
  {
    int topIndex = indexOfTop(stackNum);
    popout = stackArray[topIndex];
    stackArray[topIndex] = 0;
    stackCapacityUsed[stackNum]--;
  }

  return popout;
}

int FixedMultiStack::top(int stackNum) const
{
  if(isEmpty(stackNum))
  {
    std::cout << "Stack " << stackNum << " is empty. exit(1)\n";
    //exit(1); //Or throw an exception.
    return -1;
  }
  else{
    return stackArray[indexOfTop(stackNum)];
  }
}

bool FixedMultiStack::isEmpty(int stackNum) const
{
  return (stackCapacityUsed[stackNum] == 0);
}

bool FixedMultiStack::isFull(int stackNum) const
{
  return (stackCapacityUsed[stackNum] == stackCapacity);
}

int FixedMultiStack::indexOfTop(int stackNum) const
{
  int startIndex = stackNum * stackCapacity;
  int capacity = stackCapacityUsed[stackNum];
  return (startIndex + capacity - 1);
}

void FixedMultiStack::print_all_stack(){

  std::cout << "== print_all_stack =="<< std::endl;
  for(int i = 0; i < numOfStack ; ++i){
    std::cout << "stack: "<< i << std::endl;
    for(int j = 0; j < stackCapacityUsed[i] ; ++j){

        int indx = indexOfTop(i) - j;
        std::cout << stackArray[indx] << ",";

    }
    std::cout << "\n";
  }

}


void testing_default_init(){

  int *testing_with_default_init;
  testing_with_default_init = new int[3]();//all set to 0

  for(int i=0; i < 3; ++i)
    std::cout << testing_with_default_init[i] << std::endl;

  int *testing_no_default_init;
  testing_no_default_init = new int[3];

  for(int i=0; i < 3; ++i)
    std::cout << testing_no_default_init[i] << std::endl;


  delete [] testing_with_default_init;
  delete [] testing_no_default_init;

}

int main(){


  testing_default_init();


  FixedMultiStack mystack = FixedMultiStack(2);
  //create 3 stacks
  std::cout << "top index of stack 0 = " << mystack.top(0)<< std::endl;
  mystack.push(0,110);
  mystack.push(0,220);
  mystack.push(0,330);

  std::cout << "top index of stack 0 = " << mystack.top(0)<< std::endl;

  mystack.push(1,111);
  mystack.push(1,221);
  mystack.push(1,331);

  mystack.push(2,112);
  mystack.push(2,222);
  mystack.push(2,332);
  mystack.print_all_stack();

  //pop testing
  std::cout << "pop out:" << mystack.pop(1) << std::endl;
  mystack.print_all_stack();

  std::cout << "pop out:" << mystack.pop(1) << std::endl;
  mystack.print_all_stack();



  //push testing
  mystack.push(1,331);
  mystack.print_all_stack();


  return 0;
}
