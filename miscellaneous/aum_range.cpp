#include<bits/stdc++.h>
using namespace std;

int query(int *b,int *a,int L,int R,int s)
{

 int ans=0;
 // left part
   while(L<R && L!=0 && L%s!=0)
   {
  
   	ans+=a[L++];


   }

 //middle part
   while(L+s<=R)
   {
   	int id=L/s;
   
   	ans+=b[id];
   	L+=s;
   }
    
 //right part
   while(L<=R)
   {
  
   	ans+=a[L];
   	L++;
   }
cout<<"\n";
 return ans;
}




 int main()
 {

  int a[]={1,3,5,2,7,6,3,1,4,8};
  int n= sizeof(a)/sizeof(int);

  int s=ceil(sqrt(n));

  int *b=new int[s];
  memset(b,0,sizeof(b));
  for(int k=0;k<s;k++)
  {
    for(int i=(k*s);i<=min(n-1,(k+1)*s-1);i++)
    {
    	b[k]+=a[i];
    }

  }
 for(int j=0;j<s;j++)
 	cout<<b[j]<<" ";
 cout<<"\n";
cout<<query(b,a,1,8,s);


 return 0;}	