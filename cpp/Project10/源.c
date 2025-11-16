#include<stdio.h>
void Swap(int* x, int* y);
int main()
{
	int x, y;
	scanf_s("%d%d", &x, &y);
	Swap(&x, &y);
	printf("%d %d", x, y);


	return 0;
}

void Swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

}