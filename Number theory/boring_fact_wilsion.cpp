#include<bits/stdc++.h>
#define ll long long


/*

inverse mod

1/a mod p=???


fermat theorem

a^p-1 =~ -1 (mod p ),where p  is prime and a,p are coprime
multply by a^-1
a^p-2 =~ a^-1(mod p)


a^-1 mod p=a^p-2 mod p............(1)

Q-calc N! % p where N-P <=1000, TLE- 1s
case 1:N>p ans=0
case 2:N<p

wilsion th use

(p-1)!=~-1(mod p)
 N!*(N+1).(N+2).(N+3)....(p-1)=-1(mod p)
 x=N+1.N+2.N+3...p-1

 N!*x=~-1(mod p)
 N!=-x^-1(mod P)
 N!%p=x^-1%p=x^p-2 mod p using 1




*/
 using namespace std;

 ll pow_mod(ll n,ll p,ll m)
          {
              ll res=1;
           while(p>0)
                 {
                   if(p&1)
                    res=(res*n)%m;

                    n=(n*n)%m;
                    p=p>>1;
                 }


            return res;
            }

ll  solve(ll n, ll p)
{
   ll ans=-1;
    for(ll i=(n+1);i<=(p-1);i++)
    {
     ll temp=pow_mod(i,p-2,p);
     //cout<<temp<<endl;
     ans=(ans*temp)%p;

    }
  return ans+p;
}


int main()
{
 ll n,p;
 cin>>n>>p;
 if(n>=p)
 cout<<0<<endl;
 else
cout<<solve(n,p);
return 0;}
