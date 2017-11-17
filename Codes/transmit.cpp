#include "libs/bugabox.cpp"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	FILE *f;
	f=fopen("/dev/input/nouse0","r");
	cout<<"Enter a stream of numbers : ";
	int t=0;
	while(1)
	{
		cin>>t;
		fprintf(f,"%c",t);
	}
	fclose(f);
}
