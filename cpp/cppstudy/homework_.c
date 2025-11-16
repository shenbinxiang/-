#include<stdio.h>
int f(int n);

int memo[1000]={0,1,1};
int main ()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
    return 0;
}

int f(int n){
    if(n<=1) return n;
    if(memo[n]!=0){
        return memo[n];
    }
    memo[n]=f(n-1)+f(n-2);
    return memo[n];


}
