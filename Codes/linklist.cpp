#include "libs/bugabox.cpp"
#include <stdlib.h>

struct linklist
{
	struct node
	{
		int x;
		node *next;
	};
	node *start,*point;
	
	void declare()
	{
		start=(struct node*)malloc(sizeof(struct node));
		start->x=0;
		start->next=NULL;
	};
	void newnode(int t)
	{
		point=new node;
		point->next=NULL;
		if(start->next==NULL)
		{
			point->x=t;
			start->next=point;
		}
		else
		{
			node *tmp=new node;			
			point->next=tmp;
			point=point->next;
			point->x=t;
		}
			
	};
	void display()
	{
		point=start;
		if(point!=NULL)
			do{
				cout<<"\t"<<point->x<<"/"<<point->next;
				point=point->next;
				cout<<"\t"<<point->x<<"/"<<point->next;
			}while(point->next!=NULL);
	};
			
};



int main()
{
	linklist a;
	cout<<"\n";
	a.declare();
	a.newnode(5);
	a.newnode(6);
	a.newnode(7);
	a.newnode(8);
	cout<<"\nLOADING DONE\n";
	a.display();
}
