#include "libs/bugabox.cpp"
#define max 10

struct stack
{
	private:
	int s[max];
	int p;

	public:
	void init()
	{
		p=-1;
		cout<<"\n\nStack initialised/cleared!";
	}
	int push(int a)
	{
		if((p+1)==max)
		{
			cout<<"\n\nStack overflow!";	
			return -3296;
		}
		s[++p]=a;
		return 1;
	}
	int pop()
	{
		if(p==-1)
		{
			cout<<"\n\nStack underflow!";
			return -3296;
		}
		return(s[p--]);
	}
	void display()
	{
		cout<<"\n\n";		
		for(int i=0;i<=p;i++)
			cout<<setw(3)<<s[i];
	}
};
int main()
{
	stack s;
	s.init();
	char c;
	cout<<"\n\nPress W to push, S to pop, A/D to display, X to exit.";
	do{
		cout<<"\n>";
		c=getch();
		cout<<c;
		if(c=='W' || c=='w')
		{
			cout<<"\nElement to be pushed? : ";
			int q;
			cin>>q;
			s.push(q);
			getch();
		}
		else if(c=='s' || c=='S')
		{
			int y=s.pop();
			if(y!=-3296)			
				cout<<"\nPopped element : "<<y;
		}
		else if(c=='A'||c=='D'||c=='d'||c=='a')
			s.display();
	}while(c!='X' && c!='x');	
}

