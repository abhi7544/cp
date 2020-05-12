#include<bits/stdc++.h>
using namespace std;



 int main()
  { int n=5;
  /* cout<<"Enter number of rows/column for Magic square(n):";
   cin>>n;*/
   int b[n][n]={0};

int i=n/2,j=n-1,k=1;

 while(k<(n*n))
  {
   if (i==-1 && j==n) //3rd condition
        {
            j = n-2;
            i = 0;
        }
        else
        {
            // 1st condition helper if next number
            // goes to out of square's right side
            if (j == n)
                j = 0;

            // 1st condition helper if next number
            // is goes to out of square's upper side
            if (i < 0)
                i=n-1;
        }
        if (b[i][j]) //2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
        else
            b[i][j]=k; //set number
  k++;
        j++; i--; //1st conditio

  }
  for( i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   cout<<b[i][j]<<" ";
   cout<<"\n";
  }



  return 0;
  }
