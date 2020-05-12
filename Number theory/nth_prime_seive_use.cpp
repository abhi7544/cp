#include<bits/stdc++.h>
 using namespace std;
 bool prime[100000000];

void  prime_seive()
 {
     prime[0]=prime[1]=false;
      for(int i=3;i<=100000000;i+=2)
      {
        if(prime[i])
        {
           for(int j=i*i;j<=100000000;j+=2*i)
              prime[j]=false;

        }
    }
 }

 int nth_prime(int n)
 {
     int k=1;
     for(int i=3;i<=100000000;i+=2)
     {
         if(prime[i])
         {
             k++;
             if(k==n)
            return i;
         }
     }

 }


int main()
{
 memset(prime,true,sizeof(prime));
 int n;cin>>n;
 if(n==1)
  cout<<2;
   else
   cout<<nth_prime(n);

  return 0;}
