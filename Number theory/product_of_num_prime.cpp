#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
 using namespace std;
 //ai-1000000
 bool prime[1000001];
 vector<int>prime_seive;

 void sieve()
 {
   //boolean array - to indicate prime or not
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;

    //checking for odd numbers only


    for(ll i=3;i<=1000000;i+=2)
    {
        if(prime[i])
        {
           for(ll j=i*i;j<=1000000;j+=2*i)
              prime[j]=false;

        }
    }
  prime_seive.push_back(2);

 for(int i=3;i<=1000000;i+=2)
 {
     if(prime[i])prime_seive.push_back(i);
 }


 }

ll num_divisor(int a[],int s)
{     ll count,res=1,f=0;
    for(auto p:prime_seive)
    {

        count=0;
        for(int i=0;i<s;i++)
        {
            int n=a[i];
            while(n%p==0)
            {
                f=1;
                n=n/p;
               count++;
            }

        }

        res=(res*(count+1))%mod;
    }
return res;
}



int main()
{
sieve();
int T;cin>>T;

while(T--)
{
int n,a[15];
cin>>n;

for(int i=0;i<n;i++)
{cin>>a[i];
}
cout<<num_divisor(a,n);

}

return 0;

  }

