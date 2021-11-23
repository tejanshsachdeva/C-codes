#include <stdio.h>
#include <stdlib.h>

	struct node                   //decleration of node type of double linked list
	{	struct node* next;
	    int data;
	    struct node* prev;
	};

struct node* front=NULL;              //pointers decleration for traversal
struct node* rear =NULL;

	int isEmpty()                  //check if queue is empty or not
	{ if(front==NULL && rear==NULL)
	        return 1;
	    return 0; }

	void push(int newD)     				 //insertion of new element. Queue follows FIFO so the element will be inserted from rear
	{										  //same that happens in a queue at some counter
	    struct node* newP=malloc(sizeof(struct node));

	    newP->data=newD;    					  //creation of a node
	    newP->prev=NULL;
	    newP->next=NULL;

	    if(isEmpty()) { 							  //check if queue is blank
	        front=newP; 								 // if blank then rear and front pointer points to same node
	        rear= newP; }

	    else {              					//else using the rear pointer address of new node is linked with next part of list
	        rear->next=newP;			//and vice versa like previous part of new node is linked with new pointer
	        newP->prev=rear;
	        rear=newP;           //now rear points to last pointer
	    }
	}

	void pop()                                  //since queue follows FIFO, the element is removed from front first
	{
	    if(isEmpty())                            //looks if empty
	    {
	        printf("The queue is empty \n");
	        return;
	    }

	    struct node* temp=front;         //creation of temp node to hold rest of queue, else it will get lost

	    front=temp->next;

	    if(front==NULL)           //if only one element, delinks it from rest of queue
	        rear=NULL;
	    else
	      front->prev=NULL;       //delinks the first node, i.e. which was added before
	      free(temp);
	}

	void printqueue(struct node* front,struct node* rear)          //printing of queue
	{

	   if(!isEmpty())                           					//looks if empty
	    {
		    while(front!=rear)
		    {
		        printf("%d ",front->data);
				front=front->next;
		    }
	    printf(" %d",rear->data);
		}
		else printf("empty");
	}

	int main()
  {
  	  int ch,data;
      while(1)
    {
      	printf("\n1 to push || 2 to pop || 3 to print || 4 to exit \n");
      	scanf("%d",&ch);
			switch(ch)
			{
		 case 1: {
		 printf("Enter data for insertion \n");
		 scanf("%d",&data);
		 push(data);
		 break; }

		 case 2: {
		 	pop();
			break; }

		case 3: {
			printf("The current queue is ");
			printqueue(front,rear);
			break; }

		 case 4: {
		 	printf("\nYou Exited \n");
		 	return 0;
		 	break; }

		 default: {printf("Illegal operation\n");}
	 }
    }
	   return 0;
}

//QUEUE follows FIFO aka first in first out, so the element which gets added first , gets deleted first.
//In the above code segment, insert at front and delele at end functions are used using double linked list
//Double LL has 2 pointers and forms a double chain link with next and previous node.