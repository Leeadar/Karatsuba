#include "ItemType.h"

ItemType::ItemType(int* x, int* y, int n, int line) //ctor
{
	this->n = n;
	this->size = n / 2;
	this->a = x;
	this->c = y;
	this->b = x + n / 2;
	this->d = y + n / 2;
	this->res = new int[n * 2];
	this->ac = nullptr;
	this->bd = nullptr;
	this->e = nullptr;
	this->sumAB = nullptr;
	this->sumCD = nullptr;
	if (n % 2 != 0)
	{
		this->size = (n / 2) + 1;
	}
	this->sizeA = n / 2;
	this->sizeC = n / 2;
	this->sizeAC = (n / 2) * 2;
	this->sizeBD = size * 2;
	this->sizeE = 0;
	this->sizeSumAB = 0;
	this->sizeSumCD = 0;
	this->line = line;
}

ItemType::~ItemType() //dtor
{
	// The arrays are deleted on the iterativeKaratsuba function
}

ItemType::ItemType(const ItemType& other) //copy ctor
{
	this->n = other.n;
	this->size = other.size;
	this->a = other.a;
	this->c = other.c;
	this->b = other.b;
	this->d = other.d;
	this->res = other.res;
	this->ac = other.ac;
	this->bd = other.bd;
	this->e = other.e;
	this->sumAB = other.sumAB;
	this->sumCD = other.sumCD;
	this->sizeA = other.sizeA;
	this->sizeC = other.sizeC;
	this->sizeAC = other.sizeAC;
	this->sizeBD = other.sizeBD;
	this->sizeE = other.sizeE;
	this->sizeSumAB = other.sizeSumAB;
	this->sizeSumCD = other.sizeSumCD;
	this->sizeSums = other.sizeSums;
	this->line = other.line;
}

const ItemType& ItemType::operator=(const ItemType& other)
{
	this->n = other.n;
	this->size = other.size;
	this->a = other.a;
	this->c = other.c;
	this->b = other.b;
	this->d = other.d;
	this->res = other.res;
	this->ac = other.ac;
	this->bd = other.bd;
	this->e = other.e;
	this->sumAB = other.sumAB;
	this->sumCD = other.sumCD;
	this->sizeA = other.sizeA;
	this->sizeC = other.sizeC;
	this->sizeAC = other.sizeAC;
	this->sizeBD = other.sizeBD;
	this->sizeE = other.sizeE;
	this->sizeSumAB = other.sizeSumAB;
	this->sizeSumCD = other.sizeSumCD;
	this->sizeSums = other.sizeSums;
	this->line = other.line;
	return *this;
}

// Update the values according to the given n
void ItemType::updatdeItem(int* x, int* y, int n, int line)
{
	this->n = n;
	if (n % 2 != 0)
	{
		this->size = (n / 2) + 1;
	}
	else
	{
		this->size = n / 2;
	}

	this->a = x;
	this->c = y;
	this->b = x + n / 2;
	this->d = y + n / 2;
	this->res = new int[n * 2];
	this->sizeA = n / 2;
	this->sizeC = n / 2;
	this->line = line;
}