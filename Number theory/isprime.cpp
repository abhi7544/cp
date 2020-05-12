#include<bits/stdc++.h>
#define ll long long
 using namespace std;

//sqrt(n) method if a is divisor less than sqrt(n) than n/a is another divisor greater
//n is prime n+2 is also prime
// every prime number is of form 6k+1 or 6k-1
// every number represented as 6k+i i=0,-1,1,2,3 or 4
// 6k+2,6K+4,6k managed by divisible by 2
// 6k+3 managed by divisible by 3 and skip 5 numbers

bool isprime(ll n)
{

    if(n<=3)return n>1;

    if(n%2==0||n%3==0)return false;
    for(int i=5;i*i<=n;i+=6)

    {

           //6k-1     6k+1
        if( n%i==0||n%(i+1)==0)
            return false;
    }

    return true;
  }


int main()
{
int T;ll n;

cin>>T;

while(T--)
{
  cin>>n;

  isprime(n)?cout<<"yes":cout<<"No";
}

  return 0;}
