#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct {
  int qu[SIZE];
  int front;
  int rear;
}Queue;
typedef enum{False,True}Bool;
void reset(Queue *q)
{
  q->rear%=SIZE;
  q->front%=SIZE;
}
Bool isEmpty(Queue q)
{
  if((q.rear%SIZE)==(q.front%SIZE))
    return True;
  return False;
}
Bool isFull(Queue q)
{
  if(((q.rear+1)%SIZE)==(q.front%SIZE))
    return True;
  return False;
}
void insert(Queue *q,int item)
{
  reset(q);
  if(isFull(*q))
    printf("The queue is full\n");
  else
    q->qu[++q->rear%SIZE]=item;
}
int delete(Queue *q)
{
  reset(q);
  if(isEmpty(*q))
  {
    printf("The queue is empty\n");
    return -999999;
  }
  else
  {
    printf("The deleted element is %d\n",q->qu[++q->front%SIZE]);
    return q->qu[q->front%SIZE];
  }
}
void display(Queue q)
{
  if(isEmpty(q))
    printf("The queue is empty\n");
  else
  {
    printf("The queue is :\n");
    int i=q.front%SIZE+1;
    while((i%SIZE)!=(q.rear+1)%SIZE)
      printf("%d ",q.qu[(i++)%SIZE]);
    printf("\n");
  }
}
int main()
{
  Queue q;
  q.front=q.rear=0;
  while(1)
  {
    int sw;
    printf("Enter 1 to insert, 2 to delete, 3 to display & 4 to exit\n");
    scanf("%d",&sw);
    switch(sw)
    {
      case 1:
      printf("Enter the element to be inserted : ");
      int item;
      scanf("%d",&item);
      insert(&q,item);
      break;
      case 2:
      delete(&q);
      break;
      case 3:
      display(q);
      break;
      case 4:
      exit(0);
      break;
      default:
      printf("Enter valid input\n");
    }
  }
}
