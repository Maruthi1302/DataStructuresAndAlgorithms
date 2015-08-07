/*
 * array_quick_sort.cc
 *
 *  Created on: Aug 7, 2015
 *      Author: nxp69448
 */

#include "../headers/arrays.h"
/**
 * 1) Using static in cpp/cc file, make the variable restricted to file level, and no other translation unit can access that variable.
 * But it pollutes the global namespace.
 *
 * 2) Though we can avoid the external linkage problem by using static keyword,
 *  it still has issue of polluting global namespace.
 *   So, the batter solution is to use anonymous namespace as shown below:
 *
 */

/**
 * Without anonynomous namespace we can use static key words to achive the desired functionlaity but
 * as usual it pollutes the global namespace.
 */
//Helper APIS.
namespace {

void Swap(int *a, int *b) {
	int ival = *a;
	*a = *b;
	*b = ival;
}

int PickPivot(int ilow, int iendidx) {
	return (ilow + abs((iendidx - ilow)) / 2);
}

void PrintArray(int a[], int ilen) {
	int idx = 0;
	for (; idx <= ilen; idx++) {
		printf("%d\t", a[idx]);
	}
	printf("\n");
}

//endidx is inclusive
int Partition(int a[], int ilow, int iendidx) {

	int ipivot = PickPivot(ilow, iendidx);
	//ipivot++;
	printf("PIVOT INDEX AND ITS VALUE : %d\t%d\n", ipivot, a[ipivot]);
	int x = a[ipivot];
	//Put the pivot index at high
	Swap(&a[ipivot], &a[iendidx]);
	int iStoreIdx = ilow;
	int idx = ilow;
	for (; idx < iendidx; idx++) {
		if (a[idx] <= x) {
			Swap(&a[idx], &a[iStoreIdx]);
			iStoreIdx++;
		}
		PrintArray(a, iendidx - ilow);
	}
	Swap(&a[iStoreIdx], &a[iendidx]);
	return iStoreIdx;

}
}

namespace ARRAYS {

void* QuickSort(int a[], int istartidx, int iendidx) {
	printf("ISTART IDX: %d AND IEND IDX: %d\n", istartidx, iendidx);
	if (istartidx < iendidx) {
		int p = Partition(a, istartidx, iendidx);
		PrintArray(a, (iendidx - istartidx));
		printf("Returned Pivot IDX and Its Value: %d\t%d\n", p, a[p]);
		QuickSort(a, istartidx, p - 1);
		QuickSort(a, p + 1, iendidx);
	}
	return a;
}

void* QuickSortIterative(int a[], int istartidx, int iendidx) {
	int iStackPtr = -1;
	int stack[300] = { 0 };
	stack[++iStackPtr] = istartidx;
	stack[++iStackPtr] = iendidx;

	while (iStackPtr >= 0) {

		int itempEnd = stack[iStackPtr--];
		int itempStart = stack[iStackPtr--];

		int iPivIdx = PickPivot(itempStart, itempEnd);
		int idx = itempStart;
		int iNewPivotIdx = itempStart;
		printf("ISTART IDX: %d AND IEND IDX: %d\n", itempStart, itempEnd);
		//Put the pivot index at high
		Swap(&a[iPivIdx], &a[itempEnd]);
		//Partition
		for (; idx < itempEnd; idx++) {
			if (a[idx] <= a[itempEnd]) {
				Swap(&a[iNewPivotIdx], &a[idx]);
				iNewPivotIdx++;
			}
		}
		printf("Pivot IDX: %d AND Pivot Value: %d\n", iNewPivotIdx,
				a[iNewPivotIdx]);
		//Put Pivot Back
		Swap(&a[iNewPivotIdx], &a[itempEnd]);

		if (itempStart < (iNewPivotIdx - 1)) {
			printf("First NEW ISTART IDX: %d AND NEW IEND IDX: %d\n",
					itempStart, (iNewPivotIdx - 1));
			printf("Second NEW ISTART IDX: %d AND NEW IEND IDX: %d\n",
					(iNewPivotIdx + 1), itempEnd);
			stack[++iStackPtr] = itempStart;
			stack[++iStackPtr] = (iNewPivotIdx - 1);
		}
		if ((iNewPivotIdx + 1) < itempEnd) {
			printf("First NEW ISTART IDX: %d AND NEW IEND IDX: %d\n",
					itempStart, (iNewPivotIdx - 1));
			printf("Second NEW ISTART IDX: %d AND NEW IEND IDX: %d\n",
					(iNewPivotIdx + 1), itempEnd);
			stack[++iStackPtr] = (iNewPivotIdx + 1);
			stack[++iStackPtr] = itempEnd;
		}

	}
	return a;
}

int QuickSortDriver() {

	int i = 0;
	int* p = 0;
	int a[] = { 100, 12, 0, 3, 2, 5, 9, 1, 7, 99 };
	int b[] = { 1, 10, 5 };
	int *inputarray = a;
	int iarrayLen = 9;
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	PrintArray(inputarray, iarrayLen);
	//p = quickSort(inputarray, 0, iarrayLen);
	p = (int*) QuickSortIterative(inputarray, 0, iarrayLen);
	//quickSortDinge(inputarray,iarrayLen);
	PrintArray(p, iarrayLen);
	return 0;
}

}

