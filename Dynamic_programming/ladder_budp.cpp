#include<bits/stdc++.h>
 using namespace std;
//bottom up dp
int bu(int n,int k)
{

int *dp= new int[n+1];
dp[0]=1;


for(int i=1;i<=n;i++)
{  dp[i]=0;
    for(int j=1;j<=k &&j<=i;j++)
    {
        dp[i]+=dp[i-j];

    }
            cout<<dp[i]<<endl;


  }
  return dp[n];

}
//ways(k,k)=2 power (k-1)
int bu_opt(int n,int k)
{

int *dp=new int[n];
dp[0]=1;
for(int j=1;j<=k;j++)
dp[j]=(1<<(j-1));

for(int i=k;i<n;i++)
{
  dp[i+1]=2*dp[i]- dp[i-k];
  
   }
return dp[n];
}
//top down approach
int topd(int n,int k,int *dp)
{


if(n==0)
    return 1;
if(n<0)
    return 0;
if(dp[n]==0)
{
 for(int i=1;i<=k;++i)
dp[n]+=topd(n-i,k,dp);
}
return dp[n];
}

int main()

{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("/home/abhishek/Downloads/Algorithms/input.txt", "r", stdin);
    freopen("/home/abhishek/Downloads/Algorithms/output.txt", "w", stdout);
    #endif  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  int dp[100]={0};
//cout<<bu(6,6)<<"\n";
cout<<bu_opt(5,3)<<endl;
// cout<<topd(5,3,dp);

return 0;}
