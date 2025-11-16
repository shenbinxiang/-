#include<stdio.h>

void heapfiy(int a[], int n, int i);
void buildHeap(int a[], int n);
void heapsort(int a[], int n);
void printArray(int arr[], int size);

int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("排序前的数组: ");
	printArray(arr, size);

	//建堆
	buildHeap( arr, size);

	// 调用选择排序函数
	heapsort(arr, size);

	printf("排序后的数组: ");
	printArray(arr, size);


	return 0;
}

void heapfiy(int a[], int n, int i)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int largest = i;
	//判断谁是最大的
	if (left <n && a[left]>a[largest]) {
		largest = left;
	}
	if (right<n && a[right]>a[largest]) {
		largest = right;
	}
	//交换
	if (largest != i) {
		int temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		heapfiy(a, n, largest);
	}
}

void buildHeap(int a[], int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; i--) {
		heapfiy(a, n, i);
	}
}

void heapsort(int a[], int n)
{
	//交换底下与堆顶的元素
	int i;
	for (i = n - 1; i > 0; i--) {
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapfiy(a, i, 0);
	}
}

void printArray(int arr[], int size) 
{
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}