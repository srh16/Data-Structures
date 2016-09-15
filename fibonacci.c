#include<stdio.h>
int fib(int n)
{
  if(n<=2)
   return n-1;
  return fib(n-1)+fib(n-2);
}
int main()
{
  printf("Enter n ");
  int n;
  scanf("%d",&n);
  printf("The nth fibonacci number is %d\n",fib(n));
}
