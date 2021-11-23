  #include <stdio.h>
  #include <stdlib.h>

	struct node                   //decleration of data type of double linked list
	{	  struct node* next;
	    int data;
	    struct node* prev;
	};
	struct node *create(struct node *head,int data)        //func to link the noded together
	 {
	   struct node *temp, *tp;                             //temp pointers decl
	   temp= malloc(sizeof(struct node));                  //allocating memory
	   temp->prev= NULL;
	   temp->data= data;                                    //creating a new node
	   temp->next= NULL;

	   tp=head;
	   while(tp->next!=NULL)
	      tp = tp->next;                                       //linking the next part and previous part together
	   tp->next = temp;
	   temp->prev= tp;
	   return head;                                          //returning the head pointer
	 }

  struct node *empty(struct node* head, int data)
  {
   struct node*temp=malloc(sizeof(struct node));
   temp->prev=NULL;
   temp->data=data;
   temp->next=NULL;
   head= temp;
   return head;
  }
	 struct node *createList(struct node *head)     //create a new list in one go
	 { int n,data,i;
	 printf("Enter number of nodes  ");              //confortable input
	 scanf("%d",&n);
	 if(n==0)
	  return head;
	  printf("\nEnter element for node 1  ");       //special case for 1st node
	  scanf("%d",&data);
	  head=empty(head,data);

	  for(i=1;i<n;i++)
	  {
	    printf("Enter element for node %d  ",i+1);
	    scanf("%d",&data);
	    head=create(head,data);                       //pass the control to create func which adds at end of the 1st node
	  }
	 return head;
	 }

  struct node *insert(struct node *listp, int loc, int data) //inserts a new node to the list
  {
    struct node *newp=malloc(sizeof(struct node));
    struct node *tmp;                                  //if loc>list length, new node gets added at the end

    newp->data=data;                                           //creation of blank node//
    newp->next=NULL;
    newp->prev=NULL;

    if (listp==NULL)
    listp=newp;         //for empty list #isEmpty condition
    else

      if (loc<=1)
      {                       //error handling but logical condition
        newp->next=listp;
        listp->prev=newp;
        listp=newp;
      }
      else
      {                              //for loc>1
        tmp=listp;

        int i=1;
        while ((i++<loc-1) && tmp->next!=NULL)  //terminates at any of condition, since last node is unlinked from next side and
        tmp=tmp->next;                          //constraint till position

        newp->next=tmp->next;
        newp->prev=tmp;
        tmp->next=newp;
      }
    return listp;
  }

  struct node *delete(struct node *listp, int loc)
  {
    struct node  *temp;
    if (listp==NULL) return NULL;
    if (listp->next==NULL) {
      free(listp);
      return NULL;
    }
    if (loc<=1)             //deletes first node
    {
      temp=listp;
      listp=listp->next;
      listp->prev=NULL;
      free(temp);
    }
    else {                   //loc>1 deletes first node
      int i;
      temp=listp;
      i=1;
      while (temp->next!=NULL && i++<loc )
      temp=temp->next;
      (temp->prev)->next=temp->next;
      if (temp->next!=NULL) (temp->next)->prev=temp->prev;
      free(temp);                                          //free the pointer
    }
    return listp;
  }


  int length(struct node *listp)         //finds length of list
  {
    int len=0;
    struct node *temp=listp;
      while (temp!=NULL) {
      len++;
      temp=temp->next;
    }
    return len;
  }

  void printNode(struct node *listp)    //printing the list
  {
    struct node *tmp=listp;             //temp pointer
    printf("(");
    while (tmp!=NULL) {
      printf("%d ", tmp->data);
      tmp=tmp->next;                   //shifting to next node
    }
    printf("\b)\n");
    return;
  }

/*q1b*/ int search(struct node *listp, int data)               //searches for the data
       {
        //Returns location of item in list if present else -1
        struct node *temp=listp;
        int loc=1, z=0;
        while (temp!=NULL)
        {  //traversing the list
          if (temp->data==data)
          {
          z=1;
          break; } //checking condition
          temp=temp->next;      //moving onto next node
          loc++;
        }

         if(z==1)
          return loc;
         else
          return -1;
       }

    int main(void)
    {
      int ch;
      int loc, data;
      struct node *listp=NULL;  //local pointer for storing the func returned value
      while (1) {
       	printf("\n1 to create a list || 2 to insert || 3 to delete || 4 to search || 5 to find length || 6 to exit \n");
          	scanf("%d",&ch);
    			switch(ch)
    			{
    			case 1: {
            listp= createList(listp);
            break;
          }
          case 2:{
            printf("Give position and data to insert =");
            scanf("%d %d", &loc, &data);
            listp=insert(listp, loc, data);
            printNode(listp);
            break;}
          case 3:{
            printf("Give position for delete ");
            scanf("%d", &loc);
            listp=delete(listp, loc);
            printNode(listp);
            break;}
          case 4: {
            int item;
            printf("Search for = ");
            scanf("%d", &item);
            printf("Position = %d\n", search(listp, item));
            break;}
          case 5: {
            int len=0;
            len=length(listp);
            printf("Length of list = (%d) \n", len);
            break;}
          case 6: {
            return 0;
            break;}
          default: {printf("Illegal operation\n");}
        }
      }
      return 0;
    }