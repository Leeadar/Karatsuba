#include "stack.h"

Stack::Stack()
{
	this->top = nullptr;
}

Stack::~Stack()
{
	MakeEmpty();
}

// Delete the stack
void Stack::MakeEmpty(void)
{
	Node* temp = nullptr;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		delete[] temp;
	}
}

// Checks if the stack is empty
int Stack::IsEmpty()
{
	return (top == nullptr);
}

// Add node to the stack
void Stack::Push(ItemType& item)
{
	//top = makeNewNode(item, top);
	top = new Node(&item, top);
}

// Assumption - stcak is not empty
ItemType Stack::Pop()
{
	Node* temp = top;
	ItemType* item = new ItemType(*top->data);
	top = top->next;
	delete temp;

	return *item;
}
