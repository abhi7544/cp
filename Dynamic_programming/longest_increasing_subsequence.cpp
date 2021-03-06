

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
int lis(int *a,int n ,int *dp){
rep(i,n)
dp[i]=1;

int best = INT_MIN;
  repA(i,1,n-1){

    rep(j,i){
       if(a[j] <= a[i]){
       	dp[i] = max(1+ dp[j],dp[i]);
       }

    }

    best = max(best ,dp[i]);

  }

return best;
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
    int n;
    cin>>n;
    int *a = new int [n];
    int *dp = new int[n];
    rep(i,n)
    cin>>a[i];

    cout<<lis(a,n,dp);
    return 0;
}