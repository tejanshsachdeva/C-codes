#include<stdio.h>
#include<stdlib.h>

int n;   //global var to be used among all function segments
int convertToDiagonal(float a[][n+1],int n)   //function to convert into diadinal form or echleon form
{
    int i,j,x,y,k; int step =1;   //var decleration
    float ratio;
    for( i=0;i<n;i++)   //outer loop
    {
      for(j=0;j<n;j++)
      {
         if(j!=i)  //iterates for all elements except right diagonal elements
         {

             if(!a[i][i])   //if diagonal elements are zero, returns the index
             return i;      //else will cause error when used as denominator
             ratio=a[j][i]/a[i][i]; //ratio of next row element with first element of same col.
             for(k=0;k<n+1;k++)
                a[j][k]=a[j][k] -( ratio * a[i][k]);   //subtracts the req ratio to make the element zero

                 printf("Intermediate form after %d iteration is :\n",step);  //prints out intermediate form
                 for( x=0;x<n;x++)
                 {
                   for(y=0;y<n+1;y++)
                      printf("%.2f ",a[x][y]);
                   printf("\n");
                 }
                 printf("\n"); step++;  //step var to count no of steps the actions are performed

         }  }
     } return -1;  //returns -1 if successfully executed
}

void print(float a[][n+1],int n)   //resultant answer is the last formed element of last col. divided by
{                                   //diagonal element of same row
   int i;
   printf("Values of variables are:\n");
   for(i=0;i<n;i++)
      printf("Value[%d] or x(%d)=  %.2f\n",i,i+1,a[i][n]/a[i][i]);  //prints out the solution

}
    void trivial(float a[][n+1],int n,int temp)   //func especially for treating trivial case
    {
        //int temp=rhs(a,n);                //calling out rhs and working only if trivial
        if(temp==1)
        { printf("Trivial Solution exists for the given linear equation\n");
          for(int i=1;i<=n;i++)
          {
             printf("x(%d) = ",i);   //printing out the solution individually w/out using value[] array
          }
        } printf(" 0");
    }

    int rhs(float a[][n+1],int n)  //checks if RHS=0 r not(For Trivial Case)
    {
        int k=0,temp=2;
        while(k<=n)
        {
            if(!a[k][n]&& !a[k+1][n])   //last column checking function
            temp=1;
            k++;
        }
        return temp;                //returns 1 if trivial case
    }



int main()
{
    int i,j,k,x,y,z;
    float ratio;
   printf("Enter no of variables you are using\n");               //inputs no of var and stores in global var n
    scanf("%d",&n);
    float a[n][n+1];                                              //decleration of input array and solution array
   printf("Enter the values seperated by enter key\n");           //inputting values
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
        scanf("%f",&a[i][j]);
    }
     int r =  rhs(a,n);        //if rhs of eqn is zero i.e. the constant part, then r=1 (trivial case)

     printf("Your inputted equations in from of 2-D array is\n");  //printing out input
        for(int i=0;i<n;i++)
                 {
                   for(int j=0;j<n+1;j++)
                   printf("%.2f ",a[i][j]);
                   printf("\n");
                 }
      printf("\n");
      int f =  convertToDiagonal(a,n);   //if right side of eqn (last col) corresponding to first row is zero then, infinitely many, else inconsistent//

       if(f!=-1&&n>2&&r!=1)     //most important block to handle the special case if func eliminate didn't worked well and also not trivial
       {                    //executes only when det=0
         if(a[f][n])    //if right side of eqn corresponding to first row is zero then, infinitely many, else inconsistent//
            {printf("\nNo solution\n"); z=1; return 0;}
         else   //if its non trivial but det=0
            {printf("\nInfinitely many Solutions\n"); z=1; }
       }


        if(f==-1)       //if det is not equals to zero means solution exist
        print(a,n);

        if(r==1&&n>2)      //if its trivial
        trivial(a,n,r);    //prints out trivial case

        if(n==2){           //case for n=2 because it is showing trivialty in infinitely many case
            if(f!=-1){
                if(a[f][n]) printf("No Solution"); else printf("Infinitely many Solutions");
            }
        }
    printf("\nThanks again for using Gauss-Jordan Method \n");
    return 0;
}

//Refer ReadmeLab8 attached for any issues while compiling and also for detailed clarification of handling of exception case.