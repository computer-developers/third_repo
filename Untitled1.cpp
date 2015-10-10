////BETA VERSION .................

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int ans;
	int power;
	int matrix[2][2];
	struct node *link;
}*start;
int i,j,m[2][2],power1,m2[2][2]={NULL,NULL,NULL,NULL},y[2][2]={NULL,NULL,NULL,NULL};
int b=0;

void insert()
{
		for(i=0;i<2;i++)
		{
		for(j=0;j<2;j++)
		{
		printf("enter your value [%d][%d]: ",i,j);
		scanf("%d",&m[i][j]);
	}
	}
	printf("\nenter your power: ");
	scanf("%d",&power1);
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->power=power1;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			p->matrix[i][j]=m[i][j];
		}
	}
	p->link=start;
	start=p;
}


void display()
{
	struct node *temp;
	temp=start;
	while(temp->link!=NULL)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("%d  ",temp->matrix[i][j]);
			}
			printf("\n");
		}
		temp=temp->link;
		printf("\n\n");
	}
	for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("%d  ",temp->matrix[i][j]);
			}
			printf("\n");
		}
		printf("\n");
}

void pow()
{
	int y1;
	struct node *temp;
	temp=start;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			y[i][j]=0;
			m2[i][j]=0;
		}
	}
	while(temp!=NULL)
{	
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			y[i][j]=temp->matrix[i][j];
		}
	}
	for(y1=0;y1<temp->power;y1++)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				y[i][j]=(y[i][j])*(temp->matrix[i][j]);	
			}
		}
		
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			m2[i][j]+=y[i][j];
		}
	}
	temp=temp->link;
}
}

void display_ans()
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("%d  ",m2[i][j]);
			}
			printf("\n");
			}
			printf("\n");	
	}
	
void delete1()
{
	struct node *temp;
	temp=start;
	temp=temp->link;
	start->link=NULL;
	delete start;
	start=temp;
}


 main()
{
	int ch;
	do
	{
		printf("\n1.insert\n2.display\n3.calculation\n4.display ans\n5.exit\n6.delete\n\n");
		printf("enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			insert();
			break;
			case 2: 
			display();
			break;
			case 3:
			pow();
			break;
			case 4:
			display_ans();
			break;
			case 5:
			exit(0);
			break;
			case 6:
			delete1();
			break;
			default:
			printf("choice invalid........\n\n");
			break;
		}
	}while(ch!=5);
	getch();
}









