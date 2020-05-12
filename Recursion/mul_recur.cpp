#include<bits/stdc++.h>
 using namespace std;
int mul(int a,int b)
{
 if(b==1)return a;
 if(b<0 && a>0)return mul(b,a);
 if(a<0 && b<0)return mul(-a,-b);
 int ans=a+mul(a,b-1);
 return ans;
}

int main()
{

int a,b;cin>>a>>b;
cout<<mul(a,b);
return 0;}
