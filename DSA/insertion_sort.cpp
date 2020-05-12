#include<bits/stdc++.h>
using namespace std;

void ins_sort(int a[],int n)
{

 for (int i=1;i<n;i++)
 {int j,key;
   key=a[i];
   j=i-1;
   while(j>=0 && a[j]>key)
   {

    a[j+1]=a[j];
    j=j-1;
    a[j+1]=key;

   }


   }


  }


void print(int a[],int n)
{
  cout<<"Sorted Array: ";
  for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
   }


 int main()
  {
    int n,i,a[100];
    cout<<"size: ";
    cin>>n;
    cout<<"\nEnter Elements:";
    for(i=0;i<n;i++)
    cin>>a[i];
    ins_sort(a,n);
    print(a,n);
return 0;
  }