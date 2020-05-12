#include<bits/stdc++.h>
 using namespace std;
int sum_oddfactor(int n)
{
    while(!(n&1))n=n/2;
    int res=1;

    for(int i=3;i*i<=n;i+=2)
    {
        int cur_sum=1,cur_term=1;
        while(n%i==0)
        {
           n=n/i;

           cur_term*=i;
            cur_sum+=cur_term;

        }

        res*=cur_sum;
    }


        if(n>=2)
            res*=(n+1);

    return res;
}

int main()
{
  int n;cin>>n;
  cout<<sum_oddfactor(n);

  return 0;}
