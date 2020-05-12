#include<bits/stdc++.h>
 using namespace std;
 //                 multiples of 3 ,5,7....
 //time complexity - n/3+n/5+n/7 + ....=n*log(logn)

 void find_primes(int n)
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


 for(int i=3;i<=n;i+=2)
 {
     if(prime[i])cout<<i<<" ";
 }
cout<<endl;

 }



int main()
{

 int T,n;
 cin>>T;
 while(T--)
 {
     cin>>n;
     find_primes(n);
  }

 return 0;
  }
