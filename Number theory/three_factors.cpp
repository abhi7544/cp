#include<bits/stdc++.h>
#define ll long long
 using namespace std;
/*
Better approach is to use Number theory. According to property of perfect square, “Every perfect square(x2) always have only odd numbers of factors“.
If the square root of given number(say x2) is prime(after conforming that number is perfect square) then it must have exactly three distict factors i.e.,

A number 1 of course.
Square root of a number i.e., x(prime number).
Number itself i.e., x2.

*/
bool prime[1000000];


void  prime_seive()
 {
     prime[0]=prime[1]=false;

      for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
           for(int j=i*i;j<=n;j+=2*i)
              prime[j]=false;

        }
    }
 }
/*
bool is_prime(ll no)
{
    if(no<=1)return false;
    if(no<=3)return true;
    if(!(no&1)||no%3==0)return false;
    for(ll i=5;i*i<=no;i+=6)
    {
        if(no%i==0 ||no%(i+2)==0)return false;
    }

 return true;
}*/
bool is_tprime(ll no)
{
  ll a=sqrt(no);
   if((a*a)!=no){

        return false;

   }
  return  prime[a];

}

int main()
{
  int n;ll a[100000];
  cin>>n;

  memset(prime,true,sizeof(prime));
  for(int i=0;i<n;i++)cin>>a[i];
     prime_seive();
    for(int i=0;i<n;i++)
       {
        is_tprime(a[i])?cout<<"YES":cout<<"NO";
        cout<<endl;
       }

 return 0;}
