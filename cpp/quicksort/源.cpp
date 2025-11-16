#include<stdio.h>

void printArray(int arr[], int size);
int partition(int a[], int low, int high);
void quicksort(int a[], int low, int high);


int main()
{


	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("原始数组：\n");
	printArray(arr, n);

	quicksort(arr, 0, n - 1);

	printf("排序后的数组：\n");
	printArray(arr, n);



	return 0;
}

int partition(int a[], int low, int high)
{
	int pivot = a[high]; //选择最后一个元素作为基准元素
	int i = low - 1;   //比基准元素小的索引
	int j;
	for (j = low; j < high; j++) {
		if (a[j] < pivot) {
			i++;//移动比基准元素小的索引
			//交换
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	//将基准元素放回到正确的位置     左边比基准元素小 右边比基准元素大
	
	i++;
	int temp = a[high];
	a[high] = a[i];
	a[i] = temp;


	return i;

}

void quicksort(int a[], int low, int high)
{
	if (low < high) {
		int pi = partition(a, low, high);

		quicksort(a, low, pi - 1);
		quicksort(a, pi + 1, high);
	}
}

// 打印数组
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}