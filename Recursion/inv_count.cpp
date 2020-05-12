#include<bits/stdc++.h>
 using namespace std;

 int  merge(int a[],int s,int e)
 {
  int mid=(s+e)/2;int i=s,j=mid+1,k=s;
  int temp[100];
   int inv_count=0;
  while(i<=mid && j<=e)
  {
      if(a[i]<a[j])
        temp[k++]=a[i++];
      else
         {temp[k++]=a[j++];
           inv_count=inv_count+(mid-i+1);
         }
        }
     while(i<=mid)
        temp[k++]=a[i++];

      while(j<=e)
        temp[k++]=a[j++];


      for(int i=s;i<=e;i++)
       a[i]=temp[i];

       return inv_count;

 }


 int  merge_sort(int a[],int s,int e)
 {
    int inv_count=0;

     int mid=(s+e)/2;
   if(s<e)
   {
     inv_count+= merge_sort(a,s,mid);
     inv_count+= merge_sort(a,mid+1,e);
     inv_count+=merge(a,s,e);
   }
return inv_count;
 }

int main()
{

int n;cin>>n;
int a[100];
for(int i=0;i<n;i++)cin>>a[i];

cout<<"Number of inversion -"<<merge_sort(a,0,n-1);
for(int i=0;i<n;i++)cout<<a[i]<<" ";

return 0;}
