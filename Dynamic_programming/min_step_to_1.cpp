

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
int min_to_1_bdp(int n , int *dp){

dp[0]=dp[1]=0;

repA(i,2,n){

	int temp = INT_MAX;
	if( i%3 == 0)
		temp = dp[i/3];
    else if( i%2 == 0)
		temp = dp[i/2];

dp[i] = min(temp,dp[i-1]) +1;
	
}



return dp[n];

}

int min_to_1_tdp(int n , int *dp){

 if(n==1)
 return 0;

  int temp=INT_MAX;
  if(dp[n] != -1)
  	return dp[n];

  if(n%3 == 0){
   temp = min_to_1_tdp(n/3 , dp);
   
   }
  else if( n%2 == 0){
   temp = min_to_1_tdp(n/2 , dp);
  }

   dp[n] = min(temp, min_to_1_tdp(n-1 , dp))+1;



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
    int n;
    cin>>n;
    int *dp = new int[n+1];
    rep(i,n+1)
    dp[i]=-1;

     cout<<min_to_1_bdp(n,dp);
     cout<<min_to_1_tdp(n,dp);

    return 0;
}