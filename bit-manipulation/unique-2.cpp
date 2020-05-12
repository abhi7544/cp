#include<iostream>
using namespace std;
int main()
{
int n,u1=0,u2=0;//u1=unique number2 u2=unique number2
cin>>n;
int *a=new int[n];
int res=0,i;
for(i=0;i<n;i++)
{cin>>a[i];res^=a[i];
}
//res=u1^u2;
 /*for(i=0;i<31;i++)
 {
    if((res>>i)&1)
    { break
    */
    res=res^(res&(res-1));
 /*int s=i;//position of rightmost set bit deciding two part one containing u1 and u2
 for(i=0;i<n;i++)
 {
    if((a[i]>>s) &1)
    u1^=a[i];
    else
    u2^=a[i];
 }*/
 for(int i=0;i<n;i++)
 {
    if(a[i]&res)
         u1^=a[i];
      else
        u2^=a[i];
 }
 cout<<u1<<" "<<u2;

	return 0;
}
