#include "long_multipication.h"
#include "general_functions_header.h"
using namespace std;

//This function calaulate the multipication of 2 numbers represnted in 2 arrays with size n
int* long_multipication(int* num1_arr, int* num2_arr, int n)
{
	int* temp = new int[n + 1];
	int* res = new int[2 * n];
	int carry = 0;
	int endIndex = (2 * n) - 1;

	initArr(temp, n + 1);
	initArr(res, 2 * n);

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			temp[j + 1] = ((num2_arr[i] * num1_arr[j]) + carry) % 10;
			carry = ((num2_arr[i] * num1_arr[j]) + carry) / 10;
		}
		temp[0] = carry;
		addToRes(res, temp, endIndex, n + 1);
		endIndex--;
		carry = 0;
	}

	delete[] temp;
	return res;
}


void addToRes(int* res, int* temp, int endIndex, int tempSize)
{
	int j = endIndex;
	int i = tempSize - 1;
	int carry = 0, tempRes;

	if (j >= i)
	{
		for (j; j > endIndex - tempSize; j--)
		{
			tempRes = res[j];
			res[j] = ((temp[i]) + res[j] + carry) % 10;

			carry = ((temp[i]) + tempRes + carry) / 10;

			i--;
		}
	}

}
void printResult(int* arr, int n)
{
	int i = 0;

	while (arr[i] == 0 && i < n)
	{
		i++;
	}
	if (i == n)
	{
		cout << arr[0];
	}
	while (i < n)
	{
		cout << arr[i];
		i++;
	}
}