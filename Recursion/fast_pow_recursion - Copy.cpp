#include<bits/stdc++.h>
 using namespace std;

int pow(int a ,int b)
{
   if(b==0)return 1;
   int s_ans=pow(a,b/2);
   s_ans*=s_ans;
   if(b&1)
   s_ans=a*s_ans;

    return s_ans;
}
int main()
{

int a,b;cin>>a>>b;
cout<<pow(a,b);





  return 0;}
