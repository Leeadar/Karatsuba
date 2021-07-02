#pragma once
#include "ItemType.h"

class Node
{
public:

	ItemType* data;
	Node* next;

	Node(ItemType* data, Node* next); //ctor

	~Node(); //dtor

};