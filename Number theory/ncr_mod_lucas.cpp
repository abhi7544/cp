#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
 using namespace std;
  int x,y;
 void extended_gcd(int a ,int b)
 {
     if(b==0)
        {
        x=1;
        y=0;

        return;
        }


     extended_gcd(b,a%b);

     int Cx=y;
     int Cy=x-(a/b)*y;
     x=Cx;
     y=Cy;
 }
 int inverse_modulo(int a,int m)
  {
    extended_gcd(a,m);
    return (x+m)%m;
   }

ll fact_mod(ll n,ll r)
{
    ll res=1;
    for(ll i=n;i>=n-r+1;i--)
    {

        res=(res*i)%mod;

    }
     for(int i=r;i>0;i--)
     {res=(res*inverse_modulo(i,mod))%mod;
             cout<<res<<endl;

     }
     return res;
}

int main()
{
  ll n,r;
  cin>>n>>r;
  cout<<fact_mod(n,r);
  return 0;}
