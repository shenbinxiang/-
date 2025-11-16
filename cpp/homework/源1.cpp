#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
void Swap(int* x, int* y);
int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	Swap(&x, &y);
	printf("%d %d", x, y);


	return 0;
}

void Swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

}