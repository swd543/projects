#include "libs/bugabox.cpp"
#include <math.h>
#define max 10

struct matrix
{	
	public:
	float val[max][max]; int x,y;
	void dimInput()
	{
		cout<<"\nEnter dimensions of array [x][y]\nx=";
		cin>>x;
		cout<<"y=";
		cin>>y;
	};
	void input()
	{
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
			{
				cout<<"["<<i<<"]["<<j<<"] = ";
				cin>>val[i][j];
			}
	};
	void guiinput()
	{
		clear();
		int i=0,j=0;
		char q;
		do{
			q=getch();
			clear();			
			if(q=='w'||q=='W')(i==0)?i=x-1:i--;
				//UP
			else if(q=='s'||q=='S')(i==x-1)?i=0:i++;
				//DOWN
			else if(q=='a'||q=='A')(j==0)?j=y-1:j--;
				//LEFT
			else if(q=='d'||q=='D')(j==y-1)?j=0:j++;
				//RIGHT
			else if(q>='0'&&q<='9')
			{
				int e=q-48,k=val[i][j],f=0;
				display(i,j,'>');
				while(k>0)
				{
					k/=10,f++;
				}
				val[i][j]=(val[i][j]*pow(10,k+1))+e;
				clear();
				display(i,j,'>');
				continue;
			}
			else if(q=='c'||q=='C')
				val[i][j]=0;
			else if(q=='-')
				val[i][j]=-val[i][j];
			else if(q=='f')
			{
				clear();
				display(i,j,'f');
				cout<<"\n\nf> ";
				cin>>val[i][j];
				continue;
			}
			display(i,j,'*');
		}while(q!='x' && q!='X');
	}
	void display()
	{
		cout<<"\n";		
		for(int i=0;i<x;i++)
		{
			cout<<"|";			
			for(int j=0;j<y;j++)
				cout<<setw(5)<<val[i][j]<<setw(5);
			cout<<"|";
			cout<<"\n";
		}
	};
	void display(int a,int b,char p)
	{
		cout<<"\n";		
		for(int i=0;i<x;i++)
		{
			cout<<"|";			
			for(int j=0;j<y;j++)
				if(a==i && b==j)
					cout<<setw(4)<<p<<val[i][j]<<setw(5);
				else
					cout<<setw(5)<<val[i][j]<<setw(5);
			cout<<"|";
			cout<<"\n";
		}
	};
	void enzero()
	{		
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
				val[i][j]=0;
	};
	void echelonize(int u,int v)
	{
		int k=0;
		for(int i=u;i<x-1;i++)
			if(val[u][v]==0)
				rowSwap(u,x-1-k++);
		
		if(val[u][v]!=0)		
			for(int i=u+1;i<x-k;i++)
				rowSub(i,val[i][v]/val[u][v],u);
		v=first_nonzero_element_of_row(++u);
		if(u>=x-1  ||  v>=y-1)	return;
		else	echelonize(u,v);
	};
	float determinant(float a[max][max],int i)
	{
		float sum=0,c[i-1][i-1];
		int xx=0,yy=0;
		int aa;
		if(i==2)
			return (a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
		else
		{
			for(int k=0;k<i;k++)
			{
				for(int l=0;l<i;l++)
				{
				}
				sum+=a[k][l];
			}
		}
	};

	private:
	void rowAdd(int a,float m,int b)
	{		
		for(int i=0;i<y;i++)
			val[a][i]+=val[b][i]*m;
	};
	void rowSub(int a,float m,int b)
	{		
		for(int i=0;i<y;i++)
			val[a][i]-=val[b][i]*m;
	};
	void rowMul(int a,int b)
	{		
		for(int i=0;i<y;i++)
			val[a][i]*=b;
	};
	void rowSwap(int a,int b)
	{		
		for(int i=0;i<y;i++)
		{
			val[a][i]+=val[b][i];
			val[b][i]=val[a][i]-val[b][i];
			val[a][i]=val[a][i]-val[b][i];
		}
	};

	int first_nonzero_element_of_row(int a)
	{
		for(int i=0;i<y;i++)
			if(val[a][i]!=0)
				return i;
	}
			
};

matrix operator * (matrix x,matrix y)
{
	matrix c;
	if(x.y==y.x)
	{			
		c.x=x.x;
		c.y=y.y;
		for(int i=0;i<x.x;i++)
			for(int j=0;j<y.y;j++)
				for(int Vx=0;Vx<x.x;Vx++)
					c.val[i][j]+=x.val[i][Vx]*y.val[Vx][j];
	}
	else
		cout<<"\nInvalid operation\n";
	return c;
}

matrix operator + (matrix x,matrix y)
{
	matrix c;
	if(x.x==y.x && x.y==y.y)
	{	
		c.x=x.x;
		c.y=x.y;
		for(int i=0;i<x.x;i++)
			for(int j=0;j<y.y;j++)
				c.val[i][j]=x.val[i][j]+y.val[i][j];
	}
	else
		cout<<"\nInvalid operation\n";
	return c;
}
matrix operator - (matrix x,matrix y)
{
	matrix c;
	if(x.x==y.x && x.y==y.y)
	{	
		c.x=x.x;
		c.y=x.y;
		for(int i=0;i<x.x;i++)
			for(int j=0;j<y.y;j++)
				c.val[i][j]=x.val[i][j]-y.val[i][j];
	}
	else
		cout<<"\nInvalid operation\n";
	return c;
}


int main()
{
	matrix a;
	a.dimInput();
	//a.input();
	a.enzero();
	a.guiinput();
	a.echelonize(0,0);
	a.display();
	cout<<"\n\n\n"<<a.determinant(a.val,a.x);

/*	a.dimInput();
	a.input();
	a.display();	
	a.echelonize(0,0);
	a.display();
*/
	
}
