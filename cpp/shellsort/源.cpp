#include<stdio.h>

void sellsort(int A[], int size);
void printArray(int arr[], int size);

int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前的数组: ");
	printArray(arr, size);

	// 调用选择排序函数
	shellsort(arr, size);

	printf("排序后的数组: ");
	printArray(arr, size);

	return 0;
}

void shellsort(int A[], int size) {
	int gap;
	for (gap = size / 2; gap >= 1; gap /= 2) {
		int i;
		for (i = gap; i < size; i++) {
			int j;
			int temp = A[i];
			for (j = i; j >= gap && A[j] < A[j - gap]; j -= gap) {
				A[j] = A[j - gap];
			}
			A[j - gap] = temp;
		}
	}



}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}