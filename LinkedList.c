#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  char* data;
  struct node* next;
}
NODE;

NODE* getNode()
{
  NODE *new=(NODE*)malloc(sizeof(NODE));
  return new;
}

NODE* insertBeg(NODE *head,char *item)
{
  NODE* new;
  new=getNode();
  new->data=item;
  if(head==NULL)
    new->next=NULL;
  else
    new->next=head;
  head=new;
  return head;
}

NODE* insertEnd(NODE *head,char *item)
{
  NODE *t=head,*new;
  new=getNode();
  new->data=item;
  new->next=NULL;
  if(head==NULL)
  {
    head=new;
    head->next=NULL;
  }
  else
  {
    while(t->next!=NULL)
      t=t->next;
    t->next=new;
  }
  return head;
}

NODE* deleteBeg(NODE *head)
{
  NODE* del=head;
  if(del==NULL)
  {
    printf("Empty List\n");
    return head;
  }
  head=head->next;
  printf("Deleted item is %s\n",del->data);
  free(del);
  return head;
}

NODE* deleteEnd(NODE *head)
{
  NODE *t=head,*del;
  if(t==NULL)
    printf("Empty List\n");
  else if(t->next==NULL)
  {
    printf("Deleted item is %s\n",head->data);
    head=NULL;
  }
  else
  {
  while(t->next->next!=NULL)
    t=t->next;
  del=t->next;
  printf("Deleted item is %s\n",del->data);
  free(del);
  t->next=NULL;
  }
  return head;
}

void display(NODE* head)
{
  if(head==NULL)
    printf("Empty List\n");
  else
  {
    NODE* t=head;
    printf("List is:\n");
    do {
      printf("%s\n",t->data);
    } while((t=t->next)!=NULL);
  }
}
int main()
{
  NODE *head=NULL;
  while(1)
  {
    int sw;
    char *item;
    printf("Enter 1 to insert in the begining, 2 to insert in the end, 3 to delete from the begining, 4 to delete from the end, and 5 to exit\n");
    scanf("%d",&sw);
    switch(sw)
    {
      case 1:
      printf("Enter the item to insert\n");
      item=(char*)malloc(15*sizeof(char));
      scanf("%s",item);
      head=insertBeg(head,item);
      if(head!=NULL)
        display(head);
      break;
      case 2:
      printf("Enter the item to insert\n");
      item=(char*)malloc(15*sizeof(char));
      scanf("%s",item);
      head=insertEnd(head,item);
      if(head!=NULL)
        display(head);
      break;
      case 3:
      head=deleteBeg(head);
      if(head!=NULL)
        display(head);
      break;
      case 4:
      head=deleteEnd(head);
      if(head!=NULL)
        display(head);
      break;
      case 5:
      exit(0);
      break;
      default:
      printf("Wrong input\n");
    }
  }
}
