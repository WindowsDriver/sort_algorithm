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
			//ͨ��ѭ��ѡ���������±�
			if (arrarTest[j] > arrarTest[k])
			{
				k = j;
			}

		}

		//�����������������ŵ��±�i
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

		//����������б�������ֵ�����a�����������б�aС��ֵ�±궼������һ��λ�ã�(1, 3, 5, 7 , 2) ->(1, 3, 5, [��λ����] , 7) 
		//->(1, 3, [��λ����], 5, 7)-> 
		// 
		for (j = i - 1; j >= 0 && arrayTest[j] < tmp; j--)
		{
			arrayTest[j + 1] = arrayTest[j];
		}
		//������ѡ����ֵa,���뵽�ճ���λ�� ->(1, 2, 3, 5, 7)
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
				//����λ�ú���һ��λ��(1, 100, 23, 2) ->(1, 100,[��λ����] ,23)
				arrayTest[k + gap] = arrayTest[k];
			}

			//�����λ����->(1, 100, [��λ����], 23) -> (1, 100, 2, 23)
			arrayTest[k + gap] = tmp;

		}
	}
}

/*�鲢�����һ�ַ�ʽ start*/
void merge_sort_recursive(int arr[], int reg[], int start, int end) {
	if (start >= end)
		return;
	int len = end - start;

	// n >> 1 �ȼ��� n / 2
	int mid = (len >> 1) + start;
	int start1 = start;
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = end;

	//�ݹ�
	merge_sort_recursive(arr, reg, start1, end1);
	merge_sort_recursive(arr, reg, start2, end2);
	int k = start;

	//ȡ�������������еıȽ�С��Ԫ�طŽ�temp,�Ǹ���ȡ��Ԫ�ص����е��±������ƣ�����ȡ�������е��±겻��
	while (start1 <= end1 && start2 <= end2) {
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
		/*
		//�����������д���
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

	// �ϱߵĲ����������һ������ȡ�꣬���ĳ�������У�δȡ����Ԫ�أ����������κϲ���һ��
	while (start1 <= end1) {
		reg[k++] = arr[start1++];
	}

	// ���ĳ�������У�δȡ����Ԫ�أ����������κϲ�����);
	while (start2 <= end2) {
		reg[k++] = arr[start2++];
	}

	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}


/*
* �鲢���򡣵ݹ�棨��һ�ַ�ʽ��
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
/*�鲢�����һ�ַ�ʽ end*/


/*�鲢����ڶ��ַ�ʽ start*/

//���ж�����������a[first...mid]��a[mid...last]�ϲ�
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	//ȡ�������������еıȽ�С��Ԫ�طŽ�temp,�Ǹ���ȡ��Ԫ�ص����е��±������ƣ�����ȡ�������е��±겻��
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++]; // temp[k] = a[i]; k += 1; i+= 1;
		else
			temp[k++] = a[j++];
	}

	// �ϱߵĲ����������һ������ȡ�꣬���ĳ�������У�δȡ����Ԫ�أ����������κϲ���һ��
	while (i <= m)
		temp[k++] = a[i++];

	// ���ĳ�������У�δȡ����Ԫ�أ����������κϲ�����);
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
		mergsort(a, first, mid, temp); //�������
		mergsort(a, mid + 1, last, temp); //�ұ�����
		mergearray(a, first, mid, last, temp); // �ϲ�������������
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

/*�鲢����ڶ��ַ�ʽ end*/