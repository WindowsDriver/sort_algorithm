#pragma once
template <typename T>
void bubbleSort(T* array_, int size)
{
	T tmp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array_[j] < array_[j + 1]) {
				tmp = array_[j];
				array_[j] = array_[j + 1];
				array_[j + 1] = tmp;
			}
			else {
				continue;
			}
		}
	}
}


template<typename T>
void selectSort(T* arrarTest, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < size; j++)
		{
			//通过循环选出最大的数下标
			if (arrarTest[j] > arrarTest[k])
			{
				k = j;
			}

		}

		//交换最大数把最大数放到下标i
		T tmp = arrarTest[k];
		arrarTest[k] = arrarTest[i];
		arrarTest[i] = tmp;

	}
}

//
template<typename T>
void insertSort(T* arrayTest, int size)
{
	int i, j;
	for (i = 1; i < size; i++)
	{
		T tmp = arrayTest[i];

		//如果数组中有比这个最大值大的数a，就让数组中比a小的值下标都往后移一个位置，(1, 3, 5, 7 , 2) ->(1, 3, 5, [空位待补] , 7) 
		//->(1, 3, [空位待补], 5, 7)-> 
		// 
		for (j = i - 1; j >= 0 && arrayTest[j] < tmp; j--)
		{
			arrayTest[j + 1] = arrayTest[j];
		}
		//把上面选出的值a,插入到空出的位置 ->(1, 2, 3, 5, 7)
		arrayTest[j + 1] = tmp;
	}
}

//
template<typename T>
void shellSort(T* arrayTest, int size)
{
	int j, k;
	T tmp;
	for (int gap = size / 2; gap > 0; gap /= 2)
	{

		for (j = gap; j < size; j++)
		{
			tmp = arrayTest[j];
			for (k = j - gap; k >= 0 && (tmp < arrayTest[k]); k -= gap)
			{
				//大数位置后移一个位置(1, 100, 23, 2) ->(1, 100,[空位待补] ,23)
				arrayTest[k + gap] = arrayTest[k];
			}

			//补充空位数字->(1, 100, [空位待补], 23) -> (1, 100, 2, 23)
			arrayTest[k + gap] = tmp;

		}
	}
}

/*归并排序第一种方式 start*/
void merge_sort_recursive(int arr[], int reg[], int start, int end) {
	if (start >= end)
		return;
	int len = end - start;

	// n >> 1 等价于 n / 2
	int mid = (len >> 1) + start;
	int start1 = start;
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = end;

	//递归
	merge_sort_recursive(arr, reg, start1, end1);
	merge_sort_recursive(arr, reg, start2, end2);
	int k = start;

	//取出两个有序数列的比较小的元素放进temp,那个被取出元素的数列的下标往后移，不被取出的数列的下标不变
	while (start1 <= end1 && start2 <= end2) {
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
		/*
		//翻译上面两行代码
		if(arr[start1] <= arr[start2])
		{
		reg[k] = arr[start1];
		k++;
		start1++;
		}else{
		reg[k] = arr[start2];
		k++;
		start2++;
		}
		*/
	}

	// 上边的操作会把其中一个数列取完，如果某个数列有，未取出的元素，在这里依次合并（一）
	while (start1 <= end1) {
		reg[k++] = arr[start1++];
	}

	// 如果某个数列有，未取出的元素，在这里依次合并（二);
	while (start2 <= end2) {
		reg[k++] = arr[start2++];
	}

	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}


/*
* 归并排序。递归版（第一种方式）
* @param: {int []} arr
* @param: {const int} len
* @return null;
*/
void mergeSort2(int arr[], const int len) {
	int* reg = new int[len];
	merge_sort_recursive(arr, reg, 0, len - 1);
	delete[] reg;
	reg = NULL;
}
/*归并排序第一种方式 end*/


/*归并排序第二种方式 start*/

//将有二个有序数列a[first...mid]和a[mid...last]合并
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	//取出两个有序数列的比较小的元素放进temp,那个被取出元素的数列的下标往后移，不被取出的数列的下标不变
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++]; // temp[k] = a[i]; k += 1; i+= 1;
		else
			temp[k++] = a[j++];
	}

	// 上边的操作会把其中一个数列取完，如果某个数列有，未取出的元素，在这里依次合并（一）
	while (i <= m)
		temp[k++] = a[i++];

	// 如果某个数列有，未取出的元素，在这里依次合并（二);
	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}

void mergsort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergsort(a, first, mid, temp); //左边有序
		mergsort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); // 合并左右有序数列
	}
}

bool mergSortFunction(int a[], int size)
{
	int * temp = new int[size];
	if (temp == NULL)
	{
		return false;
	}

	mergsort(a, 0, size - 1, temp);
	delete[] temp;
	return true;
}

/*归并排序第二种方式 end*/