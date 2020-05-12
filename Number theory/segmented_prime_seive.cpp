#include<bits/stdc++.h>
#define ll long long

using namespace std;



vector<ll>p;
const int limit=pow(10,4.5);
 void sieve()
 {
     bool prime[limit+1];
      memset(prime,true,sizeof(prime));

     for(ll i=2;i<=limit;i++)
     {
       \
         if(prime[i])
         {
             cout<<i<<endl;
             p.push_back(i);
             for(ll j=i*i;j<=limit;j+=i)
                prime[j]=false;
         }
     }

cout<<p.size();

 }


 void prime_ab(ll m,ll n)
 {


    bool mark[100000];
    memset(mark,true,sizeof(mark));
     for(int i=0;p[i]*p[i]<=n && i< p.size();i++)
     {


         for(ll j=m;j<=n;j++)
         {

             if(j%p[i]==0)
             {mark[j-m]=false;//multiples of prime seive are false in m to n

             }
         }
     }

    for(ll i=m;i<=n;i++)
    {

       if(mark[i-m])
        cout<<i<<endl;
    }
 }

int main()
{
 int T;
 ll m,n;
 cin>>T;

sieve();
 while(T--)
    {
      cin>>m>>n;

      prime_ab(m,n);cout<<endl;

    }


  return 0;}
