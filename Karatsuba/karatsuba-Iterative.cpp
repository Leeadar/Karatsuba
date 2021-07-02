#include "stack.h"
#include "karatsuba-Iterative_header.h"

using namespace std;

int* iterativeKaratsuba(int* x, int* y, int n)
{
	Stack S;
	bool returnFromRecursion = false;
	ItemType Curr(x, y, n, START);
	int* returnValue = nullptr;

	do {
		if (returnFromRecursion)
		{
			Curr = S.Pop();
		}
		if (Curr.line == START)
		{
			if (Curr.n == 1)
			{
				returnFromRecursion = true;
				returnValue = twoDigitsMult(Curr.a[0], Curr.c[0]);
			}
			else
			{
				Curr.line = AFTER_FIRST;
				S.Push(Curr);
				Curr.updatdeItem(Curr.a, Curr.c, Curr.sizeA, START);
				returnFromRecursion = false;
			}
		}
		else if (Curr.line == AFTER_FIRST)
		{
			Curr.ac = returnValue;
			Curr.line = AFTER_SECOND;
			S.Push(Curr);
			Curr.updatdeItem(Curr.b, Curr.d, Curr.size, START);
			returnFromRecursion = false;
		}
		else if (Curr.line == AFTER_SECOND)
		{
			Curr.bd = returnValue;
			Curr.line = AFTER_THIRD;

			Curr.sizeAC = ((Curr.n) / 2) * 2; // Calc AC size
			Curr.sizeBD = Curr.size * 2; // Calc BD size
			Curr.sumAB = sum(Curr.a, Curr.b, Curr.n / 2, Curr.size, Curr.sizeSumAB); // Calc AB size
			Curr.sumCD = sum(Curr.c, Curr.d, Curr.n / 2, Curr.size, Curr.sizeSumCD); // Calc CD size
			makeSameSize(&(Curr.sumAB), &(Curr.sumCD), Curr.sizeSumAB, Curr.sizeSumCD, Curr.sizeSums); // Make AB & BD the same size

			S.Push(Curr);

			Curr.updatdeItem(Curr.sumAB, Curr.sumCD, Curr.sizeSums, START);
			returnFromRecursion = false;

		}
		else if (Curr.line == AFTER_THIRD)
		{
			returnFromRecursion = true;
			Curr.e = returnValue;

			calcMiddle(&(Curr.e), Curr.ac, Curr.bd, Curr.sizeSums * 2, Curr.sizeAC, Curr.sizeBD); // update e to the middle expression
			Curr.sizeE = removeLeadingZeros(&Curr.e, Curr.sizeSums * 2, Curr.sizeSums * 2 - min(Curr.sizeAC, Curr.sizeBD)); // Remove from e his leading zeros
			calcResult(Curr.res, Curr.bd, Curr.ac, Curr.e, 2 * Curr.n, Curr.sizeBD, Curr.sizeAC, Curr.sizeE); // Calculate the middle expretion in the algorithm [(a+b)*(c+d)-ac-bd]

			delete[] Curr.e;
			delete[] Curr.ac;
			delete[] Curr.bd;
			delete[] Curr.sumAB;
			delete[] Curr.sumCD;

			returnValue = Curr.res;
		}
	} while (!S.IsEmpty());

	return returnValue;
}
