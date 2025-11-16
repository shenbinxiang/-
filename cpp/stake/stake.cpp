#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_INIT_SIZE 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int conversion(int N, int d);

typedef enum {
	OK = 0,    // 操作成功
	ERROR = 1, // 一般错误
	OVER_FLOW = -1 // 溢出等特定错误
} Status;

typedef struct {
	int* base;
	int* top;
	int stacksize;
}SqStack;

Status InitStack(SqStack* S) {
	S->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S->base) exit(OVER_FLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack* S, int e) {
	if (S->top - S->base == S->stacksize)
		ERROR;
	*(S->top) = e;
	S->top++;
	return OK;
}

void GetTop(SqStack S, int* e) {
	if (S.top != S.base) {
		*e = *(S.top - 1);
	}
}
Status Pop(SqStack* S, int* e) {
	if (S->base == S->top) return ERROR;
	*e = *(S->top - 1);
	S->top--;
}
int main(int argc, char* argv[]) {
	printf("%d", conversion(42, 2));

	return 0;
}

int conversion(int N, int d) {
	SqStack S;
	InitStack(&S);
	while (N != 0) {
		Push(&S, N % d);
		N = N / d;
	}
	int e;
	int cnt = 0;
	int reust = 0;
	while (S.base != S.top) {
		Pop(&S, &e);
		cnt++;
		reust += e * pow(10, cnt);
	}
	return reust;

}
