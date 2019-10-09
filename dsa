#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
	
};
void display(struct Node * head)
{   
    printf("Linked List:\n");
	struct Node * tmp;
	tmp=head;
	while(tmp!=NULL)
	{
		printf("%d\n",tmp->data);
		tmp=tmp->next;
	}
}
struct Node * Create(int ele)
{
	struct Node * newnode;
	newnode=(struct Node *)malloc(sizeof(struct Node));
	newnode->data=ele;
	newnode->next=NULL;
	return newnode;	
}
struct Node * inserte(struct Node * head,int ele)
{
	struct Node * newnode,* tmp;
	if(head==NULL)
	{
		newnode=Create(ele);
		head=newnode;
	}
	else
	{
		tmp=head;
		while(tmp->next!=NULL)
		tmp=tmp->next;
		newnode=Create(ele);
		tmp->next=newnode;
	}
	display(head);
	return head;
}
struct Node * insertf(struct Node * head,int ele)
{
	struct Node * newnode;
	if(head==NULL)
	{
		newnode=Create(ele);
		head=newnode;
	}
	else
	{
		newnode=Create(ele);
		newnode->next=head;
		head=newnode;
	}
	display(head);
	return head;
}
struct Node * insertm(struct Node * head,int ele,int p)
{
	struct Node * newnode,* tmp;
	if(head==NULL)
	{
		newnode=Create(ele);
		head=newnode;
	}
	else
	{
		tmp=head;
		int i=1;
		while(i<p-1)
		{
			tmp=tmp->next;
			i++;
		}
		newnode=Create(ele);
		newnode->next=tmp->next;
		tmp->next=newnode;
	}
	display(head);
	return head;
}
struct Node * removef(struct Node * head)
{
    struct Node * tmp;
    tmp=head;
    printf("Removed element:%d\n",head->data);
    head=head->next;    
    tmp->next=NULL;
    free(tmp);
    display(head);
    return head;
}
struct Node * remover(struct Node * head)
{
    struct Node * tmp, *t;
    tmp=head;
    while(tmp->next!=NULL)
    { 
       t=tmp;
	   tmp=tmp->next;
    }
    printf("Removed element:%d\n",tmp->data);
    tmp->next=NULL;
    t->next=NULL;
    free(tmp);
    display(head);
    return head;
}
struct Node * removem(struct Node * head,int pos)
{
    struct Node * tmp, *t;
    tmp=head;
    int i=1;
    while(i<pos)
    { 
       t=tmp;
	   tmp=tmp->next;
	   i++;
    }
    printf("Removed element:%d\n",tmp->data);
    t->next=tmp->next;
    tmp->next=NULL;
    free(tmp);
    display(head);
    return head;
}
void main()
{
	int c,pos,e,y,x=1,r,pos1;
	struct Node * head;
	head=NULL;
	while(x<2)
	{
		
		printf("Choose:\n1.Insert Front 2.Insert End 3.Insert Middle 4.Remove Front 5.Remove Rear 6.Remove Middle");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			printf("Enter the element:");
			scanf("%d",&e);
			head=insertf(head,e);	
			break;
			case 2:
			printf("Enter the element:");
			scanf("%d",&e);
			head=inserte(head,e);	
			break;
			case 3:
			printf("Enter the element and position:");
			scanf("%d %d",&e,&pos);
			head=insertm(head,e,pos);	
			break;	
			case 4:
			head=removef(head);
			break;
			case 5:
			head=remover(head);
			break;
			case 6:
			printf("Enter the position:");
			scanf("%d",&pos1);
			head=removem(head,pos1);	
			break;	
			default:
			printf("Incorrect Choice.\n");
		}
			printf("Do you want to continue\n1.Yes 2.No");
			scanf("%d",&y);
			if(y==2)
			x++;
	}
}
