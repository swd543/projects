#include "libs/bugabox.cpp"
#define max 10
#define end 999999

struct polynomial
{
	struct node
	{
		int x_degree,y_degree,z_degree,coeff;
		node *next;
	};
	node *head,*p;
	
	void traverseTo(int a)
	{
		p=head;
		for(int i=0;i<a;i++)
			if(p->next!=NULL)
				p=p->next;
			else
				break;
	}
	bool isXYZ()
	{
		return true;
	}
	bool isNum()
	{
		return true;
	}
	bool isOp()
	{
		return true;
	}

	public:
	void init()
	{
		head=new node,p=new node;
		head=p;
		p->x_degree=0,p->y_degree=0,p->z_degree=0,p->coeff=0;
	}
/*	void insert(int e)
	{
		if(p->next!=NULL)traverseTo(end);
		p->next=new node;
		p=p->next;		
		p->data=e;
	}
	void del(int l)
	{		
		traverseTo(l-1);
		if((p->next)!=NULL)
		{
			if((p->next)->next!=NULL)
				p->next=(p->next)->next;
			else
				p->next=NULL;
		}
	}*/
	void display()
	{
		p=head;
		cout<<"\n\n";
		while(p->next!=NULL)
		{
			p=p->next;
			cout<<" + "<<p->coeff<<"x"<<p->x_degree<<"y"<<p->y_degree<<"z"<<p->z_degree;
		}
	}
	void getPoly()
	{
		int t=0;
		cout<<"\n\nEnter a polynomial in x, y and z...\n";
		do{
			p->next=new node;
			p=p->next;
			cout<<"\n\nTerm "<<++t<<":\nCoefficient::X_Degree::Y_Degree::Z_Degree ? ";
			cin>>p->coeff>>p->x_degree>>p->y_degree>>p->z_degree;
			cout<<"\nAnother polynominal? (y/n) : ";
			getch();
		}while(getch()!='n');
	}
};

polynomial operator + (polynomial a, polynomial b)
{
	polynomial c;
	a.traverseTo(0);
	b.traverseTo(0);
	cout<<"\n\n";
	return c;
}
	
	


int main()
{
	polynomial p,q;
	p.init();
	p.getPoly();
	p.display();
	q.init();
	q.getPoly();
	p.display();
	p+q.display();
}
