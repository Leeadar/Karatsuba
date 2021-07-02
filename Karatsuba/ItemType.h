#pragma once
const int START = 0;
const int AFTER_FIRST = 1;
const int AFTER_SECOND = 2;
const int AFTER_THIRD = 3;

class ItemType
{
public:

	int* a, * b, * c, * d, * ac, * bd, * e, * sumAB, * sumCD;
	int sizeSumAB, sizeSumCD, sizeSums, sizeAC, sizeBD, sizeE;
	int size, sizeA, sizeC;
	int line;
	int* x, * y, n;
	int* res;

	ItemType() = default;
	ItemType(int* x, int* y, int n, int line);// ctor
	~ItemType(); //dtor
	ItemType(const ItemType&); //copy ctor
	const ItemType& operator=(const ItemType& other);
	void updatdeItem(int* x, int* y, int n, int line);
};