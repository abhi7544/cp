#include <bits/stdc++.h>


using namespace std;


void in(int a[],int n)
 {
     for(int i=0;i<n;i++)
     cin>>a[i];
     
  }

 void out(int a[],int n)
 { int i;
     for( i=0;i<n-1;i++)
     cout<<a[i]<<",";
     cout<<a[i];
 }
 
 int max(int a[],int n)
 {
     int m=a[0];

   for(int i=0;i<n;i++)
    {
        if(a[i]>m)
        m=a[i];
    }
 return m;    
 }
 
 
 void sort(int a[],int count[],int m,int n)
 {
    for(int i=0;i<n;i++)
    {
     ++count[a[i]];    
        
    }
    cout<<endl;

    
    for(int i=0;i<m;i++)
    {
     count[i]+=count[i-1];    
        
    }
     
     int l[n];
     for(int i=0;i<n;i++)
     {
      l[count[a[i]]-1]=a[i];    
         count[a[i]]--;
     }
     out(l,n);
 }

int main()
{
 int n;
cout<<"Enter size of array:";cin>>n;
 int a[n];
 in(a,n);
 int m=max(a,n)+1;
 int count[m]={0};

 sort(a,count,m,n);
 
   return 0;
}