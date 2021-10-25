#include<stdio.h>
#include<stdlib.h>

int n;  //globally declaring n for usage among all functions
void backSubstitute(float a[][n+1],float value[],int n)    //function to backsubstitute
    {
        int i,j;
        float sum;
        value[n-1]=a[n-1][n]/a[n-1][n-1];   //last solution is the corner element of upper triangular array
                                            //stored at last index of value array
        for(i=n-2;i>=0;i--)   //loop from bottom to upper side
        {
            sum=0;
            for(j=i+1;j<n;j++)    //necessary condition to find sum of two unknown variables
                sum=sum+a[i][j]*value[j];

            value[i] = (a[i][n]-sum)/a[i][i];   //stores resultant in array value at index zero
        }
    }


    int eliminate(float a[][n+1],int n)
    {
        int i,j,x,y,k; int step =1;  //var decleration
        float ratio;
        int r =  rhs(a,n);
        for( i=0;i<n;i++)
        {
          for(j=0;j<n;j++)
          {
             if(j>i)   //the lower triangular elements general identity

             {
                 ratio=a[j][i]/a[i][i];  //divides the next row element by upper element
                 for(k=0;k<n+1;k++)   //loop to always start from 0th column till j=i
                    a[j][k]=a[j][k] -( ratio * a[i][k]);  //subtracts with the req ratio to make it zero


                 printf("Intermediate form after %d iteration is :\n",step);   //prints out the resultant array after every calculation
                 for( x=0;x<n;x++)
                 {
                   for(y=0;y<n+1;y++)
                      printf("%.2f ",a[x][y]);
                   printf("\n");

                   if(!a[x][x])    //special and imp case to check for any zero element on main diagona
                   return x;       //if main dia element is zero, **then determinant is zero** and special case arises
                 }
                 printf("\n"); step++;   //var step counts the number of intermediate steps printed

             }
          }
        }   return -1;   //returns -1 after successful execution
    }

    void print(float value[],int n)   //loop to print out solution array
    {
       int i;
       printf("Values of variables are:\n");
       for(i=0;i<n;i++)
          printf("Value[%d] or x(%d)=  %.2f\n",i,i+1,value[i]);
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
        float sum,ratio;
        printf("Enter no of variables you are using\n");   //inputs no of var and stores in global var n
        scanf("%d",&n);
        float a[n][n+1],value[n];  //decleration of input array and solution array
        printf("Enter the values seperated by enter key\n");  //inputting of values
        for(int i=0;i<n;i++)
        {
         for(int j=0;j<n+1;j++)
            scanf("%f",&a[i][j]);
        }
        printf("Your inputted equations in from of 2-D array is\n");   //printing out inputted coeff in array form
        for(int i=0;i<n;i++)
                 {
                   for(int j=0;j<n+1;j++)
                   printf("%.2f ",a[i][j]);
                   printf("\n");
                 }
        printf("\n");   //change line

       int r =  rhs(a,n);        //if rhs of eqn is zero i.e. the constant part, then r=1 (trivial case)
       int f =  eliminate(a,n);   // var f stores returned value. -1 if successful compilation(f!=-1 if determinant=0)

       if(f!=-1&&n>2&&r!=1)     //most important block to handle the special case if func eliminate didn't worked well and also not trivial
       {
       //executes only when det=0
         if(a[f][n])    //if right side of eqn corresponding to first row is zero then, infinitely many, else inconsistent//
            {printf("\nNo solution\n"); z=1; return 0;}
         else   //if its non trivial but det=0
            {printf("\nInfinitely many Solutions\n"); z=1;}

       }
        backSubstitute(a,value,n);   //calling of back substitution if above block doesnt return 0, and had exited

        if(f==-1)       //if det is not equals to zero means solution exist
        print(value,n);

        if(r==1&&n>2)      //if its trivial
        trivial(a,n,r);    //prints out trivial case

        if(n==2){           //case for n=2 because it is showing trivialty in infinitely many case
            if(f!=-1){
                if(a[f][n]) printf("No Solution"); else printf("Infinitely many Solutions");
            }
        }
        printf("\nThanks for using Gauss Elimination Method\n");
        return 0;
    }

//Refer ReadmeLab8 attached for any issues while compiling and detailed clarification of Q1(4)th part. Also look-out for comments
//In trivial case the last col. of augmeted matrix is zero


