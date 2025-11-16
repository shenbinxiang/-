#include<stdio.h>
#include<stdlib.h>

void mergesort(int A[], int left ,int right);
void printArray(int arr[], int size);
void merge(int A[], int left, int mid, int right);

int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前的数组: ");
	printArray(arr, size);

	// 调用选择排序函数
	mergesort(arr, 0,size-1);

	printf("排序后的数组: ");
	printArray(arr, size);

	return 0;
}

void mergesort(int A[], int left ,int right) {
	if(left>=right)
		return;
	int mid = (right + left) / 2;
	mergesort(A, left, mid);
	mergesort(A, mid + 1, right);
	merge(A, left, mid,right);

}


void merge(int A[], int left, int mid, int right) {

	int* temp = (int *)malloc((right- left + 1) * sizeof(int));
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right) {
		if (A[i] < A[j]) {
			temp[k++] = A[i++];
		}
		else {
			temp[k++] = A[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = A[i++];
	}
	while (j <= right) {
		temp[k++] = A[j++];
	}
	int t;
	for (t = 0; t < k; t++) {
		A[left + t] = temp[t];
	}
	free(temp);
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}