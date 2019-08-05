#include <stdio.h>
#include<iostream>
#include "algorithm.h"





int main(int argc, char** argv[])
{
	int a[6] = { 1, 3, 2, 4, 6, 5 };
	//BubbleSort<double>(a, 6);
	//insertSort<int>(a, 6);
	//shellSort(a, 6);
	mergSortFunction(a, 6);
	std::cout << a[0];
	return 0;
}