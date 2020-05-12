#include<bits/stdc++.h>
using namespace std;
void print(int a[],int hs)
   {
     if(hs!=0)
     {
     for(int i=0;i<hs;i++)
     cout<<a[i]<<" ";
     }
     else
      cout<<"\nQueue is Empty!\n";
   }

int max(int a[],int n)
{
if(n!=0)
return a[0];
else
{
  cout<<"Error:Can't return maximum ,Queue is empty!\n";
  return -1;
 }
 }

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

int Ext_max(int a[],int *n)
{

 if(*n==0)
 {
  cout<<"Error:Can't return maximum ,Queue is empty!\n";
  return -1;}
  int max=a[0];
   a[0]=a[*n-1];
   *n=*n-1;
   Heapify(a,0,*n);


return max;
  }

  int increase_val(int a[],int v,int i)
  {
   if(v<a[i])
   {
    cout<<"Can't insert negative!\n";
    return -1;
    }
    a[i]=v;
//cout<<"a["<<i<<"]="<<a[i]<<endl;
    while(i>0 && a[(i-1)/2]<a[i])
    {
     swap(a[(i-1)/2],a[i]);
     i=(i-1)/2;
    }
  }

  void insert(int a[],int v,int *n)
  {
   *n=*n+1;
   a[*n-1]=-1;
   //cout<<"v="<<v<<endl;
   int i=*n-1;
   increase_val(a,v,i);
   }



 int main()
  {

   int a[5]={8,7,4,3,1};

   int hs=sizeof(a)/sizeof(a[0]);
   int v;
   //hs=sizeof(a)/sizeof(a[0]);
   int ch,k;
  create_max_heap(a,hs);
 while(1)
 {
   cout<<"\n1.Insert\n2.Maximum\n3.Extract Maximum\n4.Exit\n5.Queue\n";
   cin>>ch;


   switch(ch)
   {
    case 1:
     cout<<"Insert:";
     cin>>v;
     //cout<<hs<<endl;
     insert(a,v,&hs);

      break;
    case 2:if(max(a,hs)!=-1)cout<<"MAX:"<<max(a,hs)<<endl; break;
    case 3:k=Ext_max(a,&hs);if(k!=-1)cout<<k<<" is extracted\n";
    print(a,hs);
     break;
    case 4:goto lb;break;
    case 5: print(a,hs);
   }

  }
   lb:


return 0;
  }