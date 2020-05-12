/*
his problem needs the basic knowledge of Inclusion-Exclusion principle. Basically, here we need to calculate count of total numbers in range [1,N] which are divisible by at least one of the numbers of the given array.

Here , all numbers of the given array will be prime, given in question less than 20
result= n/(product of all the numbers in the subset)






*/



#include<bits/stdc++.h>
#define  ll long long
using namespace std;
ll prime[8]={2,3,5,7,11,13,17,19}; //all prime numbers
ll count(ll n)
{   ll ans=0;//final  ans stored in count  of such numbers divisble by any prime numbers in range 1..n
    for(int i=1;i<(1<<8);i++) //to generate the subsets of prime array
    { int temp=i,c=0,ci=0;//ci -number of set bits in number or cardinality of set,c-to index the position of number in prime array
          ll p=1;
      while(temp >0 && p<=n)
	  {  if(temp&1)
		 {
		 p=p*prime[c];	 //p-stores the product of all such each subset
         ci++;

		 }
		 temp=temp>>1;//to check for left bit
		 c++;

	   }
/*
example
n=10
prime 2 3 5  7 11 13 17 19

2 ....ans=5 i.e 2 4 6 8 10 ci odd added
3 ....ans=8 i.e 3 6 9       ci odd added
2 3...ans=8-(10/6) removed 6 ci is even substracted
5.....ans=8+(10/5)=10
2 5   ans=10-(10/2*5)=9
.
.
.
so..... on


  */
     if(p<=n)
	 {
      if(ci&1) // if cardinality of subset is odd added bcoz its the first time its coming(inclusion)
	  ans+=(n/p);
	  else
	  ans-=(n/p);//if cardinality is even it is substracted (exclusion)

	 }
     // cout<<"ans="<<ans<<endl;


}
  return ans;
  }

int main() {
    int T;
	cin>>T;//Testcases
	ll n;//(1....n) range of numbers
    while(T--)
	{
        cin>>n;
        cout<<count(n)<<endl; //count function gives the numbers in range of (1..n) devisible by any prime number less than 20
    }

return 0;
}
