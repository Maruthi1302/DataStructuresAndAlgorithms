/*
 * arrays.h
 *
 *  Created on: Aug 7, 2015
 *      Author: nxp69448
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_
#include<iostream>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
namespace ARRAYS {

int GetMedianOfTwoSortedArrays(int firstArray[], int secondArray[], int size);
void* QuickSort(int a[], int istartidx, int iendidx);
void* QuickSortIterative(int a[], int istartidx, int iendidx);
int QuickSortDriver();

}

#endif /* ARRAYS_H_ */
