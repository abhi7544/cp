#include <bits/stdc++.h>
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
int  gcd(int a, int b){if (b!= 0) return gcd(b,a%b);else return a;}
int exp(int a ,int b){if(b==0)return 1; int ans=exp(a,b/2);ans*=ans; if(b&1) return a*ans; return ans;}
    

using namespace std;
using ll = long long;    
int n;
int min_coins(int coins[],int am,int *dp)
{
int coins_need,res;


 if(dp[am]!=-1)return dp[am];
 else{
     if(am==0)return 0;
     coins_need=INT_MAX;
     for(int i=0;i<n;i++)
     {
         if((am-coins[i])>=0)
         {
              res=min_coins(coins,am-coins[i],dp);
         }
         coins_need=min(res+1,coins_need);
     }
     dp[am]=coins_need;
      }

 return dp[am];

}
int min_coins_BU(int coins[], int am, int *dp){
 memset(dp,0,(am+1)*sizeof(int));


   repA(amount,1,am){
    dp[amount] = INT_MAX;
    rep(i,n){
      if(amount -coins[i] >=0){

         int temp = dp[amount - coins[i]];
         dp[amount] = min(dp[amount],temp+1);

          }

        }
    }


    return dp[am];

}

int main()
{int coins[]={1,7,10};
int am=15;
 int *dp=new int[am];
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("/home/abhishek/Downloads/Algorithms/input.txt", "r", stdin);
    freopen("/home/abhishek/Downloads/Algorithms/output.txt", "w", stdout);
    #endif  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 memset(dp,-1,(am+1)*sizeof(int));
 n=sizeof(coins)/sizeof(int);


cout<<min_coins(coins,am,dp)<<endl;
cout<<min_coins_BU(coins,am,dp);
return 0;}
