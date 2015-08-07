/*
 * median_of_two_sorted_arrays.cc
 *
 *  Created on: Aug 7, 2015
 *      Author: nxp69448
 */
#include "../headers/arrays.h"

/**
 * 1) Using static in cpp/cc file, make the variable restricted to file level, and no other translation unit can access that variable.
 * But it pollutes the global namespace. HOW we need to know yet.
 *
 * 2) Though we can avoid the external linkage problem by using static keyword,
 *  it still has issue of polluting global namespace.
 *   So, the batter solution is to use anonymous namespace as shown below:
 *
 */
namespace ARRAYS {

int getMedianOfTwoSortedArrays(int firstArray[], int secondArray[], int size) {

}

}
