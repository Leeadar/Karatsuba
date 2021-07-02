#pragma once
#include <iostream>

int* recursiveKaratsuba(int* x, int* y, int n);
int* twoDigitsMult(int x, int y);
int* sum(int* arr1, int* arr2, int arr1Size, int arr2Size, int& sizeSum);
int* minusArrays(int* arr1, int* arr2, int n);
void calcResult(int* res, int* bd, int* ac, int* e, int sizeRes, int sizeBD, int sizeAC, int sizeE);
void makeSameSize(int** arr1, int** arr2, int arr1Size, int arr2Size, int& size);
void calcMiddle(int** e, int* ac, int* bd, int sizeE, int sizeAC, int sizeBD);
int removeLeadingZeros(int** arr, int size, int maxRemove);
void copyNumber(int* res, int* arr, int resSize, int arrSize);
int* removeLeadZero(int* arr, int& arrSize);
int* addZerosToMiddle(int* e, int sizeE, int sizeRes);
void addToRes(int* res, int* arr, int sizeRes);