
//Christos Kokkalis 2020 - modified template class
/*---------- stack.h --------------------------------

This header file defines a Stack data type.

Basic operations:

constructor: Constructs an empty stack

empty: Checks if a stack is empty

push: Modifies a stack by adding a value at the top

top: Retrieves the top stack value; leaves stack unchanged

pop: Modifies stack by removing the value at the top

display: Displays all the stack elements

Class Invariant:

1. The stack elements (if any) are stored in positions

0, 1, . . ., myTop of myArray.

2. -1 <= myTop < STACK_CAPACITY

--------------------------------------------------------------*/
#include <iostream>

#ifndef STACK

#define STACK

using namespace std;

const int STACK_CAPACITY = 128;

template < typename StackElement>
class Stack

{
public:

	/*****Function Members *****/

	/*****Constructor *****/

	Stack();

	/*----------------------------------------------------------

	Construct a Stack object.

	Precondition: None.

	Postcondition: An empty Stack object has been constructed

	(myTop is initialized to -1 and myArray is an array

	with STACK_CAPACITY elements of type StackElement).

	-----------------------------------------------------------*/

	bool empty() const;

	/*-----------------------------------------------------------

	Check if stack is empty.

	Precondition: None

	Postcondition: Returns true if stack is empty and

	false otherwise.

	-----------------------------------------------------------*/

	void push(const StackElement& value);

	/*-----------------------------------------------------------

	Add a value to a stack.

	Precondition: value is to be added to this stack

	Postcondition: value is added at top of stack provided

	there is space; otherwise, a stack-full message is

	displayed and execution is terminated.

	-----------------------------------------------------------*/

	// void display(ostream & out) const;

	void display() const;

	/*-----------------------------------------------------------

	Display values stored in the stack.

	Precondition: ostream out is open.

	Postcondition: Stack's contents, from top down, have

	been output to out.

	-----------------------------------------------------------*/

	StackElement top() const;

	/*-----------------------------------------------------------

	Retrieve value at top of stack (if any).

	Precondition: Stack is nonempty

	Postcondition: Value at top of stack is returned, unless

	the stack is empty; in that case, an error message is

	displayed and a "garbage value" is returned.

	----------------------------------------------------------*/

	void pop();

	/*-----------------------------------------------------------

	Remove value at top of stack (if any).

	Precondition: Stack is nonempty.

	Postcondition: Value at top of stack has been removed,

	unless the stack is empty; in that case, an error

	message is displayed and execution allowed to proceed.

	----------------------------------------------------------*/

private:

	/*****Data Members *****/

	StackElement myArray[STACK_CAPACITY];

	int myTop;

};	// end of class declaration

//--- Definition of Stack constructor
template < typename StackElement>
Stack<StackElement>::Stack()

	: myTop(-1) {}

//--- Definition of empty()
template < typename StackElement>
bool Stack<StackElement>::empty() const

{
	return (myTop == -1);

}

//--- Definition of push()
template < typename StackElement>
void Stack<StackElement>::push(const StackElement& value)

{
	if (myTop < STACK_CAPACITY - 1)	//Preserve stack invariant

	{
		++myTop;

		myArray[myTop] = value;

	}
	else

	{
		cerr << "***Stack full -- can't add new value ***\n"

			"Must increase value of STACK_CAPACITY in Stack.h\n";

		exit(1);

	}
}

//--- Definition of display()

//void Stack::display(ostream & out) const
template < typename StackElement>
void Stack<StackElement>::display() const

{
	for (int i = myTop; i >= 0; i--)

		cout << myArray[i] << endl;

}

//--- Definition of top()
template < typename StackElement>
StackElement Stack<StackElement>::top() const

{
	if (!empty())

		return (myArray[myTop]);

	else

	{
		cerr << "***Stack is empty "

			" -- returning garbage value ***\n";

		return *(new StackElement);

	}
}

//--- Definition of pop()
template < typename StackElement>
void Stack<StackElement>::pop()

{
	if (!empty())

		myTop--;

	else

		cerr << "***Stack is empty -- "

		"can't remove a value ***\n";

}

#endif