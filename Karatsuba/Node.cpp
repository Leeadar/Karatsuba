#include "Node.h"

Node::Node(ItemType* data, Node* next) //ctor
{
	this->data = new ItemType(*data);
	this->next = next;
}

Node::~Node() //dtor
{
	delete data;
}
