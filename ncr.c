#include<stdio.h>
int nCr(int n,int r)
{
  int ncr_val;
  if(r==0||n==r)
      return 1;
  ncr_val=nCr(n-1,r-1)+nCr(n-1,r);
  return ncr_val;
}
int main()
{
  int n,r;
  printf("Enter the total no. of objects(n) and the no. of objects to be chosen(r)\n");
  scanf("%d %d",&n,&r);
  printf("The no. of combinations in which you can choose is %d\n",nCr(n,r));
}
