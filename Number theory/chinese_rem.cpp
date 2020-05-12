#include<bits/stdc++.h>
#define ll long long
 using namespace std;
 ll x,y;
void extended_gcd(ll a ,ll b)
{
   if(a<b) return extended_gcd(b,a);
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    extended_gcd(b,a%b);
    ll Cx=y;
    ll Cy=x-(a/b)*y;
    x=Cx;y=Cy;

}

 ll inverse_modulo(ll a,ll m)
 {
     extended_gcd( a,m);

     return (x+m)%m;
 }
ll chinese_rem(ll a[],ll r[],ll A,ll k)
{
    ll res=0;

    for(ll i=0;i<k;i++)
    {
        int pp=A/a[i];
        res+=(r[i]*pp*(inverse_modulo(pp,a[i])))%A;
    }
    return (res+A)%A;
}
int main()
{
ll *a,*r,A=1;
ll k;cin>>k;
a=new ll[k];
r=new ll[k];
for(ll i=0;i<k;i++){cin>>a[i];
A*=a[i];
}
for(ll i=0;i<k;i++)cin>>r[i];


cout<<chinese_rem(a,r,A,k);
return 0;}
