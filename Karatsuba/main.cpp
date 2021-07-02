#include "general_functions_header.h"
#include "long_multipication.h"
#include "Karatsuba.h"
#include "stack.h"
#include "karatsuba-Iterative_header.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <chrono>
#include <fstream>
#include <iomanip>

int main(void)
{
	int n = getNumberOfDigits();
	int* num1_arr = getNumber(n);
	int* num2_arr = getNumber(n);

	/// Calculate & print:
	int* res1 = long_multipication(num1_arr, num2_arr, n);
	cout << "Long multiplication : x * y = ";
	printResult(res1, 2 * n);
	cout << endl;
	int* res2 = recursiveKaratsuba(num1_arr, num2_arr, n);
	cout << "Karatsuba (recursive): x * y = ";
	printResult(res2, 2 * n);
	int* res3 = iterativeKaratsuba(num1_arr, num2_arr, n);
	cout << endl << "Karatsuba(iterative) : x * y = ";
	printResult(res3, 2 * n);

	/// Long Multipication check:
	{

		auto start = chrono::high_resolution_clock::now();
		// unsync the I/O of C and C++.
		ios_base::sync_with_stdio(false);
		long_multipication(num1_arr, num2_arr, n);// Here you put the name of the function you wish to measure
		auto end = chrono::high_resolution_clock::now();
		// Calculating total time taken by the program.
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		ofstream myfile("Long_Multipication.txt"); // The name of the file
		myfile << "Time taken by function Long Multipication is : " << fixed
			<< time_taken << setprecision(9);
		myfile << " sec" << endl;
		myfile.close();
	}
	/// Recursive Karatsuba check:
	{

		auto start = chrono::high_resolution_clock::now();
		// unsync the I/O of C and C++.
		ios_base::sync_with_stdio(false);
		recursiveKaratsuba(num1_arr, num2_arr, n);// Here you put the name of the function you wish to measure
		auto end = chrono::high_resolution_clock::now();
		// Calculating total time taken by the program.
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		ofstream myfile("Recursive_Karatsuba.txt"); // The name of the file
		myfile << "Time taken by function Recursive Karatsuba is : " << fixed
			<< time_taken << setprecision(9);
		myfile << " sec" << endl;
		myfile.close();
	}
	/// Iterative Karatsuba check:
	{

		auto start = chrono::high_resolution_clock::now();
		// unsync the I/O of C and C++.
		ios_base::sync_with_stdio(false);
		recursiveKaratsuba(num1_arr, num2_arr, n);// Here you put the name of the function you wish to measure
		auto end = chrono::high_resolution_clock::now();
		// Calculating total time taken by the program.
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		ofstream myfile("Iterative_Karatsuba.txt"); // The name of the file
		myfile << "Time taken by function Iterative Karatsuba is : " << fixed
			<< time_taken << setprecision(9);
		myfile << " sec" << endl;
		myfile.close();
	}

	delete[] num1_arr;
	delete[] num2_arr;
	delete[] res1;
	delete[] res2;
	delete[] res3;
}

