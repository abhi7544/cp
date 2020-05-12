#include<bits/stdc++.h>
using namespace std;

int  Heapify(int a[],int i,int hs)
{
 int m;
 int l=2*i+1;
 int r=(2*i)+2;
 if(l>=hs)
  return hs ;
 else{

  if(l<hs && a[l]>a[i])
  m=l;
  else m=i;
  if(r<hs && a[r]>a[m])
   m=r;

   if(i!=m)
   {  swap(a[i],a[m]);
     Heapify(a,m,hs);
    }

   }

  }


void create_max_heap(int a[],int hs)
{
 for(int i=(hs/2)-1;i>=0;i--)
  Heapify(a,i,hs);

 }

 int main()
  {

   int a[10]={35,33,42,10,14,19,7,44,26,31};
   int hs=sizeof(a)/sizeof(a[0]);

  create_max_heap(a,hs);

  for(int i=0;i<10;i++)
   cout<<a[i]<<" ";

return 0;
  }