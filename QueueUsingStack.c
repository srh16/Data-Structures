#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
typedef  struct {
  int st[10];
  int temp[10];
  int top;
  int topt;
}Stack;
void push(Stack *s,int item,int k)
{
  if(k==1)
  {
    if(s->top>=SIZE-1)
      printf("Stack Full");
    else
      s->st[++s->top]=item;
  }
  else
  {
    if(s->topt>=SIZE-1)
      printf("Stack Full");
    else
      s->temp[++s->topt]=item;
  }
}
int pop(Stack *s,int k)
{
  if(k==1)
  {
    if(s->top<=-1)
    {
      printf("Stack Empty");
      return 999;
    }
    else
      return s->st[s->top--];
  }
  else
  {
    if(s->topt<=-1)
    {
      printf("Stack Empty temp");
      return 999;
    }
    else
      return s->temp[s->topt--];
  }
}
void reverse(Stack *s,int k)
{
  int i;
  if(k==1)
    while(s->top!=-1)
      push(s,pop(s,1),2);
  else
    while(s->topt!=-1)
      push(s,pop(s,2),1);
}
void display(Stack *s)
{
  if(s->top==-1)
    printf("Stack Empty\n");
  else
    {
      int i;
      printf("The queue is:\n");
      for(i=0;i<=s->top;i++)
        printf("%d ",s->st[i]);
    }
}
int main()
{
  Stack s;
  s.top=-1;
  s.topt=-1;
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
      push(&s,item,1);
      break;
      case 2:
      reverse(&s,1);
      pop(&s,2);
      reverse(&s,2);
      break;
      case 3:
      display(&s);
      break;
      case 4:
      exit(0);
      break;
      default:
      printf("Enter valid input\n");
    }
  }
}
