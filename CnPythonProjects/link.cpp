#include "libs/bugabox.cpp"
#define end 32768

struct linklist
{
	private:
	struct node
	{
		int data;
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


	public:
	void init()
	{
		head=new node,p=new node;
		head=p;
	}
	void insert(int e)
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
	}
	void push(int a)
	{
		insert(a);
	}
	void enqueue(int a)
	{
		insert(a);
	}
	int pop()
	{
		traverseTo(0);
		if(p->next==NULL)
		{
			cout<<"\n\nUNDERFLOW!";
			return -3296;
		}
		while((p->next)->next!=0)
			p=p->next;
		int t=(p->next)->data;
		p->next=NULL;
		return t;
	}
	int dequeue()
	{
		traverseTo(0);
		if(p->next==NULL)
		{
			cout<<"\n\nUNDERFLOW!";
			return -3296;
		}
		else if((p->next)->next!=NULL)
		{
			int t=(p->next)->data;			
			p->next=(p->next)->next;
			return t;
		}
		else
		{
			int t=(p->next)->data;			
			p->next=NULL;
			return t;
		}
		
		return 0;
	}
	
	void display()
	{
		p=head;
		cout<<"\n\n";
		while(p->next!=NULL)
		{
			p=p->next;
			cout<<"--> ["<<p->data<<"/"<<p->next<<"]";
		}
	}
};
int main()
{
	linklist a;
	char c;
	a.init();
	cout<<"\n\nThis is a code to implement linkedlist as both stack and queue.";
	cout<<"\nq: push w: pop\t//Stack\no: enqueue p: dequeue\t//Queue\na: insert s: delete\nv: display\nx: exit\n";
	do{
		cout<<"\n> ";
		c=getch();
		cout<<c;
		if(c=='q'||c=='Q')
		{
			cout<<"\nElement to be pushed? ";
			int t;
			cin>>t;
			getch();
			a.push(t);
		}
		else if(c=='w'||c=='W')
		{
			int t=a.pop();
			if(t!=-3296)
				cout<<"\nPopped element : "<<t;
		}
		else if(c=='o'||c=='O')
		{
			cout<<"\nElement to be queued? ";
			int t;
			cin>>t;
			getch();
			a.enqueue(t);
		}
		else if(c=='p'||c=='P')
		{
			int t=a.dequeue();
			if(t!=-3296)
				cout<<"\nDequeued element : "<<t;
		}
		else if(c=='a'||c=='A')
		{
			cout<<"\nElement to be inserted? ";
			int t;
			cin>>t;
			getch();
			a.insert(t);
		}
		else if(c=='s'||c=='S')
		{
			cout<<"\nElement to be deleted? ";
			int t;
			cin>>t;
			getch();
			a.del(t);
		}
		else if(c=='v'||c=='V')
		{
			a.display();
			cout<<"\n\n";
		}
	}while(c!='x' && c!='X');
}
	/*a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(8);
	a.display();
	a.del(8);
	a.init();
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.display();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.display();*/
