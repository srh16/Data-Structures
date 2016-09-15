#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef  struct {
  int *st;
  int top;
  int sz;
}Stack;
void push(Stack *s,int item)
{
    if(s->top>=s->sz-1)
      {
        int *temp=(int*)realloc(s->st,sizeof(int)*(s->sz)*2);
        s->st=temp;
        s->sz*=2;
      }
      s->st[++s->top]=item;
}
int pop(Stack *s)
{
    if(s->top<=-1)
    {
      printf("Stack Empty");
      return 999;
    }
    else
      return s->st[s->top--];
}
void display(Stack *s)
{
  if(s->top==-1)
    printf("Stack Empty\n");
  else
    {
      int i;
      printf("The stack is:\n");
      for(i=0;i<=s->top;i++)
        printf("%d ",s->st[i]);
      printf("\n");
    }
}
int main()
{
  Stack *s;
  s->top=-1;
  s->sz=SIZE;
  s->st=(int*)malloc(SIZE*sizeof(int));
  while(1)
  {
    int sw;
    printf("Enter 1 to push, 2 to pop, 3 to display & 4 to exit\n");
    scanf("%d",&sw);
    switch(sw)
    {
      case 1:
      printf("Enter the element to be pushed : ");
      int item;
      scanf("%d",&item);
      push(s,item);
      break;
      case 2:
      pop(s);
      break;
      case 3:
      display(s);
      break;
      case 4:
      exit(0);
      break;
      default:
      printf("Enter valid input\n");
    }
  }
}
