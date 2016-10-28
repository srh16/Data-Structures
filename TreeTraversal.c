#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* left;
	struct node* right;
	int data;
}node;

typedef struct {
	node** stk;
	int top;
	int size;
}Stack;

typedef struct {
	node** que;
	int f;
	int r;
	int size;
}Queue;

Stack* getStack(int stkSize)
{
	Stack *s=(Stack*)malloc(sizeof(Stack));
	s->stk=(node**)malloc(stkSize*sizeof(node*));
	s->size=stkSize;
	s->top=-1;
	return s;
}

Queue* getQueue(int queSize)
{
	Queue *q=(Queue*)malloc(sizeof(Queue));
	q->que=(node**)malloc(queSize*sizeof(node*));
	q->size=queSize;
	q->f=0;
	q->r=0;
	return q;
}

int isStackEmpty(Stack *s)
{
	return s->top==-1;
}

int isStackFull(Stack *s)
{
	return (s->top)==(s->size-1);
}

void push(Stack *s,node* n)
{
	if(isStackFull(s))
		s->stk=(node**)realloc(s->stk,(s->size=(s->size+5))*sizeof(node*));
	s->stk[++s->top]=n;
}

node* pop(Stack *s)
{
	if(isStackEmpty(s))
		return NULL;
	else
		return s->stk[s->top--];
}

void resetFR(Queue *q)
{
	q->f=q->f%q->size;
	q->r=q->r%q->size;
}

int isQueueEmpty(Queue *q)
{
	resetFR(q);
	return q->f==q->r;
}

int isQueueFull(Queue *q)
{
	resetFR(q);
	return ((q->r)+1)%q->size==q->f;
}

void insert(Queue *q,node* n)
{
	if(isQueueFull(q))
	{
		node** temp=(node**)malloc((2+(q->size))*sizeof(node*));
		int i=((q->f+1)%q->size),j=0;
		while((i%q->size)!=(q->r%q->size))
			temp[++j]=q->que[(i++)%q->size];
		temp[++j]=q->que[(i++)%q->size];
		free(q->que);
		q->que=temp;
		q->f=0;
		q->r=j;
		q->size+=1;
	}
	q->que[(++q->r)%q->size]=n;
}

node* delete(Queue *q)
{
	if(isQueueEmpty(q))
		return NULL;
	return q->que[(++q->f)%q->size];
}

node* getNode(int d)
{
	node* new=(node*)malloc(sizeof(node));
	new->left=NULL;
	new->right=NULL;
	new->data=d;
	return new;
}

node* insertBST(node* root,int item)
{
	if(root==NULL)
		root=getNode(item);
	else
	{
		if(item>root->data)
			root->right=insertBST(root->right,item);
		else if(item<root->data)
			root->left=insertBST(root->left,item);
		else
			printf("Duplicate element\n");
	}
	return root;
}

node* insertTree(node* root, int item)
{
	if(root==NULL)
		root=getNode(item);
	else
	{
		int ch;
		printf("Enter 1 to insert left or 2 to insert right\n");
		scanf("%d",&ch);
		if(ch==1)
			root->left=insertTree(root->left,item);
		else if(ch==2)
			root->right=insertTree(root->right,item);
		else
			printf("Wrong input\n");
	}
	return root;
}

int searchBST(node* root,int item)
{
	if(root==NULL)
		return 0;
	else if(root->data==item)
		return 1;
	else if(root->data>item)
		searchBST(root->left,item);
	else
		searchBST(root->right,item);
}

void inorderI(node* root)
{
	if(root==NULL)
	{
		printf("Empty Tree\n");
		return;
	}
	else
	{
		Stack *s=getStack(1);
		while(1)
		{
			while(root!=NULL)
			{
				push(s,root);
				root=root->left;
			}
			root=pop(s);
			if(root==NULL)
				break;
			else
			{
				printf("%d  ",root->data);
				root=root->right;
			}
		}
		printf("\n");
	}
}

void preorderI(node* root)
{
	if(root==NULL)
	{
		printf("Empty Tree\n");
		return;
	}
	else
	{
		Stack *s=getStack(1);
		while(1)
		{
			while(root!=NULL)
			{
				printf("%d  ",root->data);
				push(s,root);
				root=root->left;
			}
			root=pop(s);
			if(root==NULL)
				break;
			else
				root=root->right;
		}
		printf("\n");
	}
}

void postorderI(node* root)
{
	if(root==NULL)
	{
		printf("Empty Tree\n");
		return;
	}
	else
	{
		Stack *s1=getStack(1);
		Stack *s2=getStack(1);
		node* t;
		push(s1,root);
		while(!isStackEmpty(s1))
		{
			t=pop(s1);
			push(s2,t);
			if(t->left!=NULL)
				push(s1,t->left);
			if(t->right!=NULL)
				push(s1,t->right);
		}
		while(!isStackEmpty(s2))
		{
			printf("%d  ",pop(s2)->data);
		}
		printf("\n");
	}
}

void inorderR(node* root)
{
	if(root!=NULL)
	{
		inorderR(root->left);
		printf("%d ",root->data);
		inorderR(root->right);
	}
}

void preorderR(node* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorderR(root->left);
		preorderR(root->right);
	}
}

void postorderR(node* root)
{
	if(root!=NULL)
	{
		postorderR(root->left);
		postorderR(root->right);
		printf("%d ",root->data);
	}
}

void levelOrderI(node* root)
{
	if(root!=NULL)
	{
		Queue *q=getQueue(5);
		insert(q,root);
		while(!isQueueEmpty(q))
		{
			node* t=delete(q);
			printf("%d  ",t->data);
			if(t->left!=NULL)
				insert(q,t->left);
			if(t->right!=NULL)
				insert(q,t->right);
		}
		printf("\n");
	}
	else
		printf("Empty Tree\n");
}

node* getSuccessor(node* t)
{
	t=t->right;
	while(t->left!=NULL)
		t=t->left;
	return t;
}

node* searchDeleteBST(node* root,int item)
{
	if(root==NULL)
		return root;
	else
	{
		if(item>root->data)
			root->right=searchDeleteBST(root->right,item);
		else if(item<root->data)
			root->left=searchDeleteBST(root->left,item);
		else
		{
			if(root->left==NULL && root->right==NULL)
			{
				free(root);
				return NULL;
			}
			else if(root->left==NULL || root->right==NULL)
			{
				node * t=(root->left==NULL)?root->right:root->left;
				free(root);
				return t;
			}
			else
			{
				node* t=getSuccessor(root);
				root->data=t->data;
				root->right=searchDeleteBST(root->right,t->data);
			}
		}
		return root;
	}
}

int main()
{
	node* root=NULL;
	printf("Press 1 to enter all elements at once\n");
	int i,item,n=0;
	scanf("%d", &i);
	if(i==1)
	{
		printf("Enter the number of elements\n");
		scanf("%d",&i);
		printf("Enter the elements\n");
		while(n<i)
		{
			scanf("%d",&item);
			root=insertTree(root,item);
			n=n+searchBST(root,item);
		}
	}
	else
	{
		while(1)
		{
			printf("Enter 1 to insert an element into tree\n");
			scanf("%d",&i);
			if(i==1)
			{
				printf("Enter item to insert\n");
				scanf("%d",&item);
				root=insertBST(root,item);
			}
			else
				break;
		}
	}
	printf("\nInorder Traversal::\n");
	inorderI(root);
	printf("\n\nPreorder Traversal::\n");
	preorderI(root);
	printf("\n\nPostorder Traversal::\n");
	postorderI(root);
	printf("\n\nLevelorder Traversal::\n");
	levelOrderI(root);
	printf("\n\nEnter element to delete: ");
	int del;
	scanf("%d",&del);
	root=searchDeleteBST(root,del);
	printf("\nInorder Traversal::\n");
	inorderI(root);
	printf("\n\nPreorder Traversal::\n");
	preorderI(root);
	printf("\n\nPostorder Traversal::\n");
	postorderI(root);
	printf("\n\nLevelorder Traversal::\n");
	levelOrderI(root);
}