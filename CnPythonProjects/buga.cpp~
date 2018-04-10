#include "libs/bugabox.cpp"		//custom library, contains some essential functions



struct inputBox
{
	int e[100],length;
	int C;
	void displayArray()
	{
		cout<<"\n";
		for(int i=0;i<length;i++)
		cout<<e[i]<<"\t";
	};
	void displayArray(int x,int b)
	{
		cout<<"\n";
		for(int i=0;i<length;i++)
			if(i==x || i==b)
				cout<<"*"<<e[i]<<"\t";
			else
				cout<<e[i]<<"\t";
	};

	int getArray()
	{
		length=0;
		cout<<"\nEnter the elements one by one, and press <ENTER> after each entry. -3296 to exit loop.\n";
	
		do	cin>>e[length++];
		while(e[length-1]!=-3296);
	
		e[length--]=0;
		return length;
	};
	int bubbleSort()
	{		
		int i,j,tmp=0,c=0;
		cout<<"\nATTEMPTING BUBBLE SORT,\n";
		for(i=0;i<length;i++)
		{
			for(j=0;j<length-i-1;j++)
			{
				if(e[j+1]<e[j])
				{
					displayArray(j,j+1);
					tmp=e[j+1];
					e[j+1]=e[j];
					e[j]=tmp;
					tmp=0;
					c++;
				}
			}
		}
		displayArray();
		cout<<"\nTIME COMPLEXITY : "<<c<<" Iterations.\n";
		return c;
	};
	int selectionSort()
	{
		int i,j,tmp=0,c=0;
		cout<<"\nATTEMPTING SELECTION SORT,\n";
		for(i=0;i<length-1;i++)
		{
			for(j=i+1;j<length;j++)
			{
				if(e[j]<e[i])
				{	
					displayArray(j,i);
					tmp=e[i];
					e[i]=e[j];
					e[j]=tmp;
					tmp=0;
					c++;
				}
			}
		}
		displayArray();
		cout<<"\nTIME COMPLEXITY : "<<c<<" Iterations.\n";
		return c;
	};
	int insertionSort()
	{
		int i,j,temp=0,c=0;
		cout<<"\nATTEMPTING INSERTION SORT,\n";
		
		for (int i = 0; i < length; i++)
		{
			j = i;
			
			while (j > 0 && e[j] < e[j-1])
			{
				displayArray(j,j-1);
				temp = e[j];
				e[j] = e[j-1];
				e[j-1] = temp;
				j--,c++;
			 }
		}
		displayArray();
		cout<<"\nTIME COMPLEXITY : "<<c<<" Iterations.\n";
		return c;
	};

	
	int quickie(int left, int right)
	{
	      int i = left, j = right;
	      int tmp;
	      int pivot = e[(left + right) / 2];
	 
	      /* partition */
		while (i <= j)
		{
	            while (e[i] < pivot)
	            	i++;
	            while (e[j] > pivot)
	            	j--;
			if (i <= j)
			{
				displayArray(i,j);
		            	tmp = e[i];
		            	e[i] = e[j];
		            	e[j] = tmp;
		            	i++;
		            	j--,C++;
			}
		};
	 
	      /* recursion */
		if (left < j)
			quickie(left, j);
		if (i < right)
			quickie(i, right);
		return C;
	};
	void quickSort()
	{
		C=0;
		cout<<"\nATTEMPTING QUICK SORT,\n";
		quickie(0,length-1);
		displayArray();
		cout<<"\nTIME COMPLEXITY : "<<C<<" Iterations.\n";
	}			
};


int main()
{
	clear();
	cout<<"\nThis program uses different sorting techniques and compares the efficiency of each algorithm\n\n";
	
	inputBox a,b;
	a.getArray();
	b=a;
	b.bubbleSort();
	b=a;
	b.selectionSort();
	b=a;
	b.insertionSort();
	b=a;
	b.quickSort();
	
}
