#pragma once
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

//Checks if a string is valid and non negative number
bool check_number(string str);


//Gets the number of digits from user, and checks if it's valid
int getNumberOfDigits();


//Gets a number from user, and checks if it's valid
int* getNumber(int size);

//initialize all cells in array to zeros
void initArr(int* arr, int length);

int min(int num1, int num2);