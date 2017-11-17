#include "libs/bugabox.cpp"

struct student
{
	char name[10];
	int age,gr_no,roll_no;
	float cpi;
	
	void input()
	{
		cout<<"\nEnter student's name : ";
		cin>>name;
		cout<<"Enter gr_no : ";
		cin>>gr_no;
		cout<<"Enter roll_no : ";
		cin>>roll_no;
		cout<<"Enter cumulative cpi : ";
		cin>>cpi;
		cout<<"Entry successfully added!\n";
		getch();
	};
	void display()
	{
		cout<<std::setw(10)<<name<<std::setw(10)<<gr_no<<setw(5)<<roll_no<<setw(5)<<cpi<<"\n";
	}
};

int main()
{
	clear();
	student s[20];
	char c='\0';
	int l=0;
	cout<<"\n\n\tSTUDENT DATABASE\n";
	do{
		c='\0';
		cout<<"\n1. Add an entry\n2. Remove an entry\n3. Locate an entry\n4. Display entire database\nX. Exit\n\nEnter your choice : ";
		c=getch();
		cout<<c;
		if(c=='x' || c=='X') return 0;
		else if(c<'1' || c>'4') cout<<"\nInvalid entry, please try again.";
		

		switch(c)
		{
			case '1' :	s[l++].input();
					break;
			case '2' :	int t;
					cout<<"\nRemove entry at position? (1 for initial element) : ";
					cin>>t;
					getch();
					for(int i=--t;i<l;i++)
						s[i]=s[i+1];
					l--;
					break;
			case '4' :	for(int i=0;i<l;i++)
					{
						cout<<"\n"<<i+1;
						s[i].display();
					}
					break;	
		}
	}while(c!='1' || c!='2' || c!='3' || c!='4');
}
