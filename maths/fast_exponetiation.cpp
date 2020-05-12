#include<bits/stdc++.h>
 using namespace std;

int exp(int a ,int b)
{

    if(b==0)return 1;

    int ans=exp(a,b/2);
    ans*=ans;
    if(b&1)
        return a*ans;
    return ans;

}

int main()
{

int a,b;
cin>>a>>b;

cout<<exp(a,b);
  return 0;}
