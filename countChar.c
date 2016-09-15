#include<stdio.h>
int countChar(char *c, char f,int count)
{
  if(c[0]=='\0')
   return count;
  if(c[0]==f)
   count++;
  countChar(c+1,f,count);
}
int main()
{
  char c[100];
  printf("Enter the string :");
  scanf("%s",c);
  printf("Enter a character to be counted :");
  char f;
  scanf(" %c",&f);
  printf("The count of the entered charcter is %d\n",countChar(c,f,0));
}
