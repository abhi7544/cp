#include<bits/stdc++.h>
 using namespace std;
int sum_evenfactor(int n)
{
 if(n&1)return 0;
int res=1;
 for(int i=2;i*i<=n;i++)
 {
      int count=0,cur_sum=1,cur_term=1;
     while(n%i==0)
     {
         count++;
         n=n/i;
         if(i==2 && count==1)cur_sum=0;

         cur_term*=i;
         cur_sum+=cur_term;
     }
     res*=cur_sum;

     if(n==1)break;
     }





     if(n>=2)
        res*=(n+1);


return res;
}

int main()
{
int n;cin>>n;
cout<<sum_evenfactor(n)<<endl;
return 0;}
