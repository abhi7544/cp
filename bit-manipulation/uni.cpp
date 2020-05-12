#include<bits/stdc++.h>
 using namespace std;


int main()
{
int a[]={7,3,7,3,4,72,4,7,3,4};
int n=sizeof(a)/sizeof(int);

int cnt[32]={0};
for(int i=0;i<n;i++)
{
int no=a[i];
int j=0;
while(no>0)
{
   cnt[j]+=(no&1);
   no=(no>>1);
   j++;
}
  }
int res=0;
  for(int i=0;i<32;i++)
 {
   cnt[i]=cnt[i]%3;
   res=res+(1<<i)*cnt[i];
   cout<<cnt[i]<<" ";
 }cout<<"unique number ="<<res;









  return 0;}
