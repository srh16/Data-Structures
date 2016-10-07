#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int isPresent(char *data,NODE *head)
{
    NODE *t = head;
    while (t != NULL)
    {
        if(strcmp(t->data,data)==0)
            return 1;
        t = t->next;
    }
    return 0;
}

NODE* Union(NODE** ret,NODE* s1,NODE* s2)
{
    NODE *temp=s1;
    *ret=NULL;
    printf("Union:\n");
    if(s1==NULL&&s2==NULL)
    {
      printf("Empty List\n");
      return NULL;
    }
    else if(s1==NULL)
    {
      display(s2);
      return s2;
    }
    else if(s2==NULL)
    {
      display(s1);
      return s1;
    }
    else
    {
        char *item=(char*)malloc(15*sizeof(char));
        do
        {
          item=s1->data;
          insertEnd(*ret,item);
          s1=s1->next;
        }while(s1!=NULL);
        s1=temp;
        do
        {
          if(!isPresent(s2->data,s1))
          {
            item=s2->data;
            insertEnd(*ret,item);
          }
          s2=s2->next;
        }while(s2!=NULL);
        display(ret);
        return ret;
    }
}

int main()
{
  NODE *head1=NULL,*head2=NULL,**un=NULL;
  *un=NULL;
  while(1)
  {
    int sw,ck;
    char *item;
    printf("Enter the elements of set 1:\n");
    do {
      item=(char*)malloc(15*sizeof(char));
      printf("Enter the item to insert\n");
      scanf("%s",item);
      head1=insertEnd(head1,item);
      printf("Enter 1 to enter another element to set\n");
      scanf("%d",&ck);
    } while(ck==1);
    printf("Enter the elements of set 2:\n");
    do {
      item=(char*)malloc(15*sizeof(char));
      printf("Enter the item to insert\n");
      scanf("%s",item);
      head2=insertEnd(head2,item);
      printf("Enter 1 to enter another element to set\n");
      scanf("%d",&ck);
    } while(ck==1);
    un=Union(un,head1,head2);
    printf("Enter 0 to exit\n");
    scanf("%d",&sw);
    if(sw==0)
      exit(0);
  }
}
