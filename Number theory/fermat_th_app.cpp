#include<bits/stdc++.h>
#define ll long long
 using namespace std;


 ll pow(ll a,ll b)
 {
   ll res=1;

 while(b>0)
 {
    if(b&1) res=res*a;

    a=a*a;
  b=b>>1;
  }

return res;
 }


 ll mod =1000000007;

ll stringToInt(string a,ll mod)
{
    ll res=0;

    for(auto x:a)
    {
       res=(res*10)%mod+(x-48);
       res%=mod;
    }

    return res;
}

int main()
{
string a,b;
//cin>>a>>b;

//ll x=stringToInt(a,mod);
//ll y=stringToInt(a,mod-1);
ll m,n;
cin>>m>>n;
cout<<pow(m,n);
return 0;

}
