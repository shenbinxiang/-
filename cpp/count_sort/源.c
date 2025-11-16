#include<stdio.h>
#include<stdlib.h>

void countsort(int A[], int size);
void printArray(int arr[], int size);

int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前的数组: ");
	printArray(arr, size);

	countsort(arr, size);

	printf("排序后的数组: ");
	printArray(arr, size);

	return 0;
}

void countsort(int A[], int size) {
	
	//找到最大值
	int i;
	int max = A[0];
	for (i = 0; i < size; i++) {
		if (max < A[i]) {
			max = A[i];
		}
	}
	//找到最小值
	int min = A[0];
	for (i = 0; i < size; i++) {
		if (min > A[i]) {
			min = A[i];
		}
	}
	//创建计数数组 范围是最大值减去最小值加一
	int* count = (int*)malloc(sizeof(int) * (max - min + 1));
	for (i = 0; i < max - min + 1; i++) {
		count[i] = 0;
	}

	//循环计数
	for (i = 0; i<size; i ++) {
		count[A[i]-min]++;
	}
	//创建累加数组
	for (i = 0; i < max-min+1; i++) {
		count[i] += count[i - 1];
	}
	//最后排序
	int* output = (int*)malloc(sizeof(int) * size);
	for (i = size - 1; i > 0; i--) {
		output[i]=
	}


}

void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}