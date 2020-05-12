#include<bits/stdc++.h>
 using namespace std;
 vector<int>find_primes(int n)
 {
   bool prime[n+1];//boolean array - to indicate prime or not
     vector<int>prime_seive;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;

    //checking for odd numbers only


    for(int i=3;i<=n;i+=2)
    {
        if(prime[i])
        {
           for(int j=i*i;j<=n;j+=2*i)
              prime[j]=false;

        }
    }
  prime_seive.push_back(2);

 for(int i=3;i<=n;i+=2)
 {
     if(prime[i])prime_seive.push_back(i);
 }
return prime_seive;

 }


vector<int>prime_factors(int n)
{
  vector<int> prime=find_primes(n);

  cout<<endl;
  vector<int>factors;
  int i=0;
  int p=prime[0];

    while(p*p<=n)
     {
///factors.push_back(p);
 factors.push_back(p);
           while(n%p==0)
           {

           n=n/p;


           }


       i++;
       p=prime[i];

      }

 if(n!=1){
        factors.push_back(n);
    }
return factors;
}

int main()
{


int n;
cin>>n;

vector<int>factors=prime_factors(n);


for(auto x:factors)cout<<x<<" ";


return 0;

  }

