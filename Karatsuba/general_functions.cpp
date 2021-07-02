#include "general_functions_header.h"
#include <iostream>
#include <string>

using namespace std;

//check if n is natural 
bool check_number(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
		{
			return false;
		}
	}
	return true;
}

int getNumberOfDigits()
{
	string str;
	int n;

	cout << "Enter the number of digits: ";
	cin >> str;

	if (check_number(str) && str[0] != '0') 
	{
		n = stoi(str);
		return n;
	}
	else if(str.length()==1 && str[0] == '0')
	{
		exit(1);
	}
	else
	{
		cout << "Wrong input" << endl;
		exit(1);
	}

}

int* getNumber(int size)
{
	int* num_arr = new int[size];
	string str;
	static int num_player = 1;

	cout << "Enter number " << num_player << " :";
	cin >> str;
	if (!(check_number(str) && str.length() == size))
	{
		cout << "Wrong input" << endl;
		exit(1);
	}

	for (int i = 0; i < size; i++)
	{
		num_arr[i] = str[i] - '0';
	}

	num_player++;

	return num_arr;
}


//initialize all cells in array to zeros
void initArr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = 0;
	}
}


int min(int num1, int num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}
