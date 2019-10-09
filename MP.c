#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
struct Flight 
{
	char name[5];
	int passengers;
	int cabin;
	float duration;
	time_t dept;
	char dest[20];
	struct Flight * next;
	struct Flight * prev;
};
char stack[50];
int top=-1;
struct Flight * Create()
{
	struct tm  T,* T1;
	struct Flight * newnode;
	newnode=(struct Flight *)malloc(sizeof(struct Flight));
	printf("Enter Name Of Flight:\n");
	scanf("%s",newnode->name); 
	printf("Enter No. of Passengers:\n");
	scanf("%d",&newnode->passengers);
	printf("Enter No. of Cabin Crew:\n");
	scanf("%d",&newnode->cabin);
	printf("Enter Duration:\n");
	scanf("%f",&newnode->duration);
	printf("Enter Destination:\n");
	scanf("%s",newnode->dest);
    time(&newnode->dept);
    printf("The Current Time is: %s", ctime(&newnode->dept));
	printf("Enter Time remaining for Flight:\n");
	scanf("%d",&T.tm_sec);
	T1=localtime(&newnode->dept);
	int s,m;
	if(T.tm_sec>=60)//seconds more than 60
	{
		s=T.tm_sec%60;
		m=T.tm_sec/60;
		if((s+T1->tm_sec)>59)
		{
			T1->tm_sec=s+T1->tm_sec-60;
			m++;
			if((m+T1->tm_min)>59)
			{
				T1->tm_min=m+T1->tm_min-60;
				T1->tm_hour++;
			}
			else
			T1->tm_min=m+T1->tm_min;
		}
		else if((s+T1->tm_sec)<=59)
		{
			T1->tm_sec=s+T1->tm_sec;
			T1->tm_min+=m;
		}
	}
	else//seconds less than 60
	{
		if((T1->tm_sec+T.tm_sec)<60)
		T1->tm_sec=T1->tm_sec+T.tm_sec;
		else if((T1->tm_sec+T.tm_sec)>+60)
		{
			T1->tm_sec=T1->tm_sec+T.tm_sec-60;
			T1->tm_min++;
			if(T1->tm_min>59){
			T1->tm_min-=60;
			T1->tm_hour++;}
		}
	}
	printf("The Departure Time is: %s", asctime(T1));
	newnode->dept=asctime(T1);
	int i=0;
	for(i=0;newnode->dest[i]!='\0';i++)
		newnode->dest[i]=toupper(newnode->dest[i]);
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;	
}
struct Destination * C()
{
	struct Destination * nn;
	nn=(struct Destination *)malloc(sizeof(struct Destination));
	nn->nextf=NULL;
	nn->nextd=NULL;
	return nn;
}
struct Flight * AddF(struct Flight * head)
{
	struct Flight * tmp,* tmp1;
	tmp=head;
	if(head==NULL)
	{
		tmp1=Create();
		head=tmp1;
		struct Destination * st;
		st=start;
		while(st!=NULL)
		{
			if(strcmp(head->dest,st->nd)==0)
			{
				start->nextf=head;
				head=NULL;
			}
			else if(strcmp(head->dest,st->nd)==0)
			{
				start->nextf=head;
				head=NULL;
			}
			else if(strcmp(head->dest,st->nd)==0)
			{
				start->nextf=head;
				head=NULL;
			}
			else if(strcmp(head->dest,st->nd)==0)
			{
				start->nextf=head;
				head=NULL;
			}
			else if(strcmp(head->dest,st->nd)==0)
			{
				start->nextf=head;	
				head=NULL;
			}
			st=st->nextd;
		}
	}
	else
	{
		while(tmp->next!=NULL)
		{
			tmp=tmp->next;
		}
	}
	return head;
}
void printF(struct Flight * head1)
{
	struct Flight * temp;
	temp=head1;
	while(temp!=NULL)
	{
	printf("%d",temp->cabin);
	temp=temp->next;
	}
}
void printD()
{
	struct Destination * temp;
	temp=start;
	struct Flight * head;
	head=start->nextf;
	while(temp->nextd!=NULL)
	{
	printf("%s",temp->nd);
	printF(head);
	temp=temp->nextd;
	}
}
struct Flight * Admin(struct Flight *head)
{
	char u[40],p[40];
	int i=0;
	printf("Enter Username:");
	gets(u); 
	printf("Enter Password:");
    do
	{ 
        p[i]=getch(); 
        if(p[i]!='\r')
			printf("*"); 
        i++; 
    }while(p[i-1]!='\r'); 
    p[i-1]='\0'; 
	printf("\nEnter Y to SEE Password or press N:");
	char c=getch();
	int cmp=strcmp(u,"admin");
	int c1=strcmp(p,"admin");
	if(c=='Y'||c=='y')
	{	
    	printf("\nYou have entered %s as password.",p);   
    }
    if(cmp==0&&c1==0)
    {
		MessageBoxA(NULL,"Welcome Pranav","",MB_OK);
	}
	else
	{
		MessageBoxA(NULL,"Invalid Login","",MB_OK);
	}
	int z=0;
	while(z<1)
	{
		if(cmp==0&&c1==0)
    	{
			printf("\nCHOOSE:\n1.ADD Flight \n2.ADD Destination \n3.REMOVE Flight \n4.REMOVE Destination\n5.CHECK Flights\n6.Exit:");
			int q=0,i;
			char d[50];
			scanf("%d",&q);
			switch(q)
			{
				
			}
		}
	}
	return head;
}
int main()
{
	FILE *fp;
	time_t t;
	char data[50],d1[50];
    time(&t);
    printf("The Current Time is: %s", ctime(&t));
    start=NULL;   
    int i =0;
	fp=fopen("Destination.c","r");
	while( fgets ( data, 50, fp ) != NULL )
	{ 
	   if(start==NULL)
	   {
		start=C();
		strcpy(start->nd,data);
	   }   
	   else
	   {
		p=start;
		while(p->nextd!=NULL)
		p=p->nextd;
		nn=C();
		p->nextd=nn;
		strcpy(p->nd,data);
	   }
	}
	fclose(fp);
    struct Flight * head;
    head=NULL;
    head=Admin(head);
    return 0;
}
