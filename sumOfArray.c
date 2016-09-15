#include<stdio.h>
int sum(int a[],int n)
{
  if(n==0)
    return a[n];
  return a[n]+sum(a,n-1);
}
int main()
{
  printf("The sum of the array is :");
  int a[]={10,20,30,40,50,60,70,80,90,100};
  int n=9;
  printf("%d\n",sum(a,n));
}
