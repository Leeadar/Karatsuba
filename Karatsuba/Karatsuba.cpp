#include "Karatsuba.h"
#include "general_functions_header.h"
#include <iostream>
using namespace std;

int* recursiveKaratsuba(int* x, int* y, int n)
{
	int* a, * b, * c, * d, * ac, * bd, * e, * sumAB, * sumCD;
	int sizeSumAB, sizeSumCD, sizeSums, sizeAC, sizeBD, sizeE;
	int size = n / 2;
	int sizeA = n / 2, sizeC= n/2;

	if (n == 1)
	{
		return twoDigitsMult(x[0], y[0]);
	}
	int* res= new int[n*2];

	a = x;
	c = y;

	b = x + n/2;
	d = y + size;

	if (n % 2 != 0) 
	{
		size = (n / 2) + 1;
	}

	ac = recursiveKaratsuba(a, c, sizeA);
	bd = recursiveKaratsuba(b, d, size); 
	sizeAC = (n / 2) * 2;
	sizeBD = size * 2;

	sumAB = sum(a, b, n/2 , size , sizeSumAB);
	sumCD = sum(c, d, n/2 , size , sizeSumCD);

	makeSameSize(&sumAB, &sumCD, sizeSumAB, sizeSumCD, sizeSums);

	e = recursiveKaratsuba(sumAB, sumCD, sizeSums);

	calcMiddle(&e, ac, bd, sizeSums*2, sizeAC, sizeBD); //update e to the middle expression

	sizeE = removeLeadingZeros(&e, sizeSums * 2, sizeSums * 2 - min(sizeAC, sizeBD));

	calcResult(res, bd, ac, e, 2 * n, sizeBD, sizeAC, sizeE);

	delete[] e;
	delete[] ac;
	delete[] bd;
	delete[] sumAB;
	delete[] sumCD;

	return res;
}


/// V
void calcMiddle(int** e, int* ac, int* bd, int sizeE, int sizeAC, int sizeBD)
{
	int x;
	int* eMinusAC, * eMinusACMinusBD;
	int* newAC = new int[sizeE];
	int* newBD = new int[sizeE];

	copyNumber(newAC, ac, sizeE, sizeAC);
	copyNumber(newBD, bd, sizeE, sizeBD);

	eMinusAC = minusArrays(*e, newAC, sizeE);
	eMinusACMinusBD = minusArrays(eMinusAC, newBD, sizeE);
	
	delete[] newAC;
	delete[] newBD;
	delete[] eMinusAC;
	delete[] *e;

	*e = eMinusACMinusBD;
}


int removeLeadingZeros(int** arr, int size, int maxRemove)
{
	if (*arr[0] != 0 || maxRemove==0)
	{
		return size;
	}
	int i = 0;
	while (*(*arr+i) == 0 && i < maxRemove)
	{
		i++;
	}
	int* newArr = new int[size - i];

	for (int j = 0; j < size - i ; j++)
	{
		newArr[j] = *(*arr+i + j);
	}
	delete[] * arr;
	*arr = newArr;
	return size - i;
}
///XXX
void makeSameSize(int** arr1, int** arr2, int arr1Size, int arr2Size, int& size)
{
	int n;
	int* temp;
	if (arr1Size == arr2Size)
	{
		size = arr1Size;
		return;
	}
	if (arr1Size > arr2Size)
	{
		n = arr1Size;
		temp = new int[n];
		copyNumber(temp, *arr2, n, arr2Size); //insert arr2 to temp with leading zeros
		delete[] *arr2;
		*arr2 = temp;
		size = n;
	}
	else
	{
		n = arr2Size;
		temp = new int[n];
		copyNumber(temp, *arr1, n, arr1Size); //insert arr1 to temp with leading zeros
		delete[] *arr1;
		*arr1 = temp;
		size = n;
	}
}

int* twoDigitsMult(int x, int y)
{
	int* res = new int[2];

	res[1] = (x * y) % 10;

	res[0] = (x * y) / 10;

	return res;
}

//assumption - arr2Size>= arr1Size
int* sum(int* arr1, int* arr2, int arr1Size, int arr2Size, int& sizeSum)
{
	int n, carry = 0, temp;
	int* res;

	n = arr2Size;
	sizeSum = n + 1;
	res = new int[sizeSum];

	copyNumber(res, arr1, sizeSum, arr1Size); //insert arr1 to res with leading zeros

	for (int i = n - 1; i >= 0; i--) //add Arr2 to res
	{
		temp = res[i + 1];
		res[i+1] = (res[i + 1] + arr2[i] + carry) % 10;
		carry = (temp + arr2[i] + carry) / 10;
	}
	res[0] = carry;

	res = removeLeadZero(res, sizeSum);	// delete leading zero if carry=0
	return res;
}

int* removeLeadZero(int* arr, int& arrSize)
{
	if (arr[0] != 0)
	{
		return arr;
	}
	int size = arrSize - 1;
	int* temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i + 1];
	}
	delete[] arr;
	arrSize = size;
	return temp;
}


void copyNumber(int* res, int* arr, int resSize, int arrSize)
{
	int j = 0;
	int diff = resSize - arrSize;
	for (int i = 0; i < resSize; i++)
	{
		if (i < diff)
		{
			res[i] = 0;
		}
		else
		{
			res[i] = arr[j];
			j++;
		}
	}
}

// assumption the number in arr1 is bigger than arr2
int* minusArrays(int* arr1, int* arr2, int n)
{
	int* res = new int[n];

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr1[i] < arr2[i] && i> 0 )
		{
			arr1[i] += 10;
			arr1[i - 1] -= 1;
		}

		res[i] = arr1[i] - arr2[i];
	}
	return res;
}

//  
void calcResult(int* res, int* bd, int* ac, int* e , int sizeRes, int sizeBD, int sizeAC, int sizeE)
{
	int* newE;
	int* newAC = new int[sizeRes];

	copyNumber(res, bd, sizeRes, sizeBD); //insert bd to res with leading zeros

	for (int i = 0; i < sizeRes; i++) //create a new AC
	{
		if (i < sizeAC)
		{
			newAC[i] = ac[i];
		}
		else
		{
			newAC[i] = 0;
		}
	}

	addToRes(res, newAC, sizeRes); //add ac to res

	newE = addZerosToMiddle(e, sizeE, sizeRes);

	addToRes(res, newE, sizeRes); // add newE to res

	delete[] newE;
	delete[] newAC;
}

void addToRes(int* res, int* arr, int sizeRes)
{
	int temp;
	int carry = 0;
	for (int i = sizeRes - 1; i >= 0; i--)
	{
		temp = res[i];
		res[i] = (res[i] + arr[i] + carry) % 10;
		carry = (temp + arr[i] + carry) / 10;
	}
}

int* addZerosToMiddle(int* e, int sizeE , int sizeRes)
{
	int* newE = new int[sizeRes];
	int j = sizeRes - 1;
	int count = 0;
	int zeros = sizeRes / 2;
	int rightZeros = zeros / 2;
	if (zeros % 2 != 0)
	{
		rightZeros++;
	}
	while (count < rightZeros)
	{
		newE[j] = 0;
		count++;
		j--;
	}
	count = sizeE - 1;
	while (count >= 0)
	{
		newE[j] = e[count];
		count--;
		j--;
	}
	while (j >= 0)
	{
		newE[j] = 0;
		j--;
	}
	return newE;
}
