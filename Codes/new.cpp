#include <stdio.h>

struct node{
	node* next;
	int data;
};

node head;

int main(){

	printf("Yolo\n");

	int x=3296;
	int *p;
	p=x;
	int &r=x;

	for(int i=0;i<10;i++){
		printf("Original: %d Pointer: %d Reference: %d\n",x,*p,r++);
	}
	return 0;
}