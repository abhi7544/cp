#include<bits/stdc++.h>
 using namespace std;

int gcd(int a ,int b)
{ //base case
  if(b==0)
    return a;

    gcd(b,a%b);

  }



  //lcm(a,b)*gcd(a,b)=a*b
  void  lcm(int a,int b)
  {
     cout<<(a*b);
    }


int main()
{
int a,b;
cin>>a,b;
if(a<b)
{
   a=(a^b);
   b=(a^b);
   a=(a^b);
}
cout<<a<<b;
cout<<gcd(a,b)<<endl;
cout<<a<<" "<<b;
//lcm(a,b);
  return 0;}
