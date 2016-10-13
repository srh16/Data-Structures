#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int coef;
  int deg;
  struct node* next;
}NODE;

NODE* getNode()
{
  NODE *new=(NODE*)malloc(sizeof(NODE));
  return new;
}

void display(NODE* head)
{
  if(head==NULL)
    printf("Empty List\n");
  else
  {
    NODE* t=head;
    //printf("List is:\n");
    do {
      if(t->deg!=0)
        printf("%dx^%d ",t->coef,t->deg);
      if(t->deg==0)
        printf("%d ",t->coef);
      if(t->next!=NULL)
        printf("+ ");
    } while((t=t->next)!=NULL);
    printf("\n");
  }
}

void printEntered(NODE* head1,NODE* head2)
{
  printf("Polynomial 1:\t");
  display(head1);
  printf("Polynomial 2:\t");
  display(head2);
}

int isPresent(int ex,NODE *t)
{
    while (t != NULL)
    {
        if(t->deg==ex)
            return 1;
        t = t->next;
    }
    return 0;
}

NODE* findSameDegNode(NODE* t, int ex)
{
  while (t != NULL)
  {
      if(t->deg==ex)
          break;
      t = t->next;
  }
  return t;
}

NODE* insertSort(NODE *head,int coef,int deg)
{
  if(coef==0)
    return head;
  if(isPresent(deg,head))
  {
    (findSameDegNode(head,deg)->coef)+=coef;
    return head;
  }
  NODE *t=head,*new;
  new=getNode();
  new->coef=coef;
  new->deg=deg;
  if(t==NULL)
  {
    head=new;
    head->next=NULL;
  }
  else if(t->deg<deg)
  {
      new->next=head;
      head=new;
  }
  else
  {
    while(t->next!=NULL&&(t->next->deg)>deg)
      t=t->next;
    new->next=t->next;
    t->next=new;
  }
  return head;
}

NODE* add(NODE* p1,NODE* p2)
{
  NODE* ret=NULL;
  while(p1!=NULL)
  {
    ret=insertSort(ret,p1->coef,p1->deg);
    p1=p1->next;
  }
  while(p2!=NULL)
  {
    /*if(isPresent(p2->deg,ret))
      (findSameDegNode(ret,p2->deg)->coef)+=p2->coef;
    else*/
      ret=insertSort(ret,p2->coef,p2->deg);
    p2=p2->next;
  }
  return ret;
}

NODE* sub(NODE* p1,NODE* p2)
{
  NODE* ret=NULL;
  while(p1!=NULL)
  {
    ret=insertSort(ret,p1->coef,p1->deg);
    p1=p1->next;
  }
  while(p2!=NULL)
  {
    /*if(isPresent(p2->deg,ret))
      (findSameDegNode(ret,p2->deg)->coef)-=p2->coef;
    else*/
      ret=insertSort(ret,-(p2->coef),p2->deg);
    p2=p2->next;
  }
  return ret;
}

NODE* mult(NODE* p1,NODE* p2)
{
  NODE* ret=NULL,*temp=p2;
  while(p1!=NULL)
  {
    while(p2!=NULL)
    {
      ret=insertSort(ret,(p1->coef)*(p2->coef),(p1->deg)+(p2->deg));
      p2=p2->next;
    }
    p2=temp;
    p1=p1->next;
  }
  return ret;
}

NODE* input(NODE *head)
{
  int ck,ex,cof;
  do {
    printf("Enter the degree of the term\n");
    scanf("%d",&ex);
    printf("Enter the coefficient of the term\n");
    scanf("%d",&cof);
    head=insertSort(head,cof,ex);
    display(head);
    printf("Enter 1 to enter another term to polynomial. Enter any other number to stop entering\n");
    scanf("%d",&ck);
  } while(ck==1);
  return head;
}

NODE* inputAll(NODE* head)
{
  int terms,ex,cof;
  printf("Enter the no. of terms\n");
  scanf("%d",&terms);
  printf("Enter the terms (coefficient degree . . .)\n");
  while(terms--)
  {
    scanf("%d %d",&cof,&ex);
    head=insertSort(head,cof,ex);
  }
  display(head);
  return head;
}

int main()
{
  int sw,eAll;
  NODE *head1=NULL,*head2=NULL;
  printf("Do you want to enter all elements at once?If yes enter 1, else enter any other number\n");
  scanf("%d",&eAll);
  if(eAll==1)
  {
    printf("Enter the elements of polynomial 1:\n");
    head1=inputAll(head1);
    printf("Enter the elements of polynomial 2:\n");
    head2=inputAll(head2);
  }
  else
  {
    printf("Enter the elements of polynomial 1:\n");
    head1=input(head1);
    printf("Enter the elements of polynomial 2:\n");
    head2=input(head2);
  }
  while(1)
  {
    printf("Enter 1->Add, 2->Subtract, 3->Multiply, & 4->Exit\n");
    scanf("%d",&sw);
    switch(sw)
    {
      case 1:
      printEntered(head1,head2);
      printf("Sum is:\t\t");
      display(add(head1,head2));
      break;
      case 2:
      printEntered(head1,head2);
      printf("Difference is:\t");
      display(sub(head1,head2));
      break;
      case 3:
      printEntered(head1,head2);
      printf("Product is:\t");
      display(mult(head1,head2));
      break;
      case 4:
      exit(0);
      break;
      default:
      printf("Wrong Input\n");
    }
  }
}
