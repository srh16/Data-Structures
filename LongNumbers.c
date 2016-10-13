#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  struct node* prev;
  int num;
  struct node* next;
}NODE;

NODE* getNode()
{
  NODE* new=(NODE*)malloc(sizeof(NODE));
  return new;
}

NODE* initialize(NODE* h)
{
  h->next=h;
  h->prev=h;
  return h;
}

NODE* insertBeg(NODE* head,int item)
{
  NODE* new=getNode();
  new->num=item;
  new->next=head->next;
  new->prev=head;
  head->next->prev=new;
  head->next=new;
  return head;
}

NODE* insertEnd(NODE* head,int item)
{
  NODE* new=getNode();
  new->num=item;
  new->next=head;
  new->prev=head->prev;
  head->prev->next=new;
  head->prev=new;
  return head;
}

NODE* add(NODE* n1,NODE* n2)
{
  NODE *t1=n1->prev,*t2=n2->prev;
  NODE* ret=getNode();
  ret=initialize(ret);
  int c=0,s=0;
  while(t1!=n1&&t2!=n2)
  {
    s=(t1->num+t2->num+c)%10;
    c=(t1->num+t2->num+c)/10;
    ret=insertBeg(ret,s);
    t1=t1->prev;
    t2=t2->prev;
  }
  while(t1!=n1)
  {
    s=(t1->num+c)%10;
    c=(t1->num+c)/10;
    ret=insertBeg(ret,s);
    t1=t1->prev;
  }
  while(t2!=n2)
  {
    s=(t2->num+c)%10;
    c=(t2->num+c)/10;
    ret=insertBeg(ret,s);
    t2=t2->prev;
  }
  if(c!=0)
    ret=insertBeg(ret,c);
  return ret;
}

void display(NODE* h)
{
  NODE* temp=h->next;
  while(temp!=h)
  {
    printf("%d",temp->num);
    temp=temp->next;
  }
  printf("\n");
}

int main()
{
  char *n1,*n2;
  int l1,l2;
  NODE *h1=getNode(),*h2=getNode(),*sum;
  h1=initialize(h1);
  h2=initialize(h2);
  printf("Enter the length of the first number\n");
  scanf("%d",&l1);
  printf("Enter the the first number\n");
  n1=(char*)malloc(l1*sizeof(char));
  scanf("%s",n1);
  printf("Enter the length of the second number\n");
  scanf("%d",&l2);
  printf("Enter the the second number\n");
  n2=(char*)malloc(l2*sizeof(char));
  scanf("%s",n2);
  int i;
  for(i=0;i<l1;i++)
    h1=insertEnd(h1,n1[i]-'0');
  for(i=0;i<l2;i++)
    h2=insertEnd(h2,n2[i]-'0');
  printf("The first number is: ");
  display(h1);
  printf("The second number is: ");
  display(h2);
  sum=add(h1,h2);
  printf("The sum is: ");
  display(sum);
}
