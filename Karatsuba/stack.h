#pragma once
#include "ItemType.h"
#include "karatsuba-Iterative_header.h"
#include "Karatsuba.h"
#include "general_functions_header.h"
#include <iostream>
#include "Node.h"

class Stack
{
private:
	Node* top;

public:
	Stack(); //ctor
	~Stack(); //dtor

	void MakeEmpty();
	int IsEmpty();
	void Push(ItemType& item);
	ItemType Pop();

};