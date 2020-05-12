

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

int max_profit_BU(int wines[] , int size){
int dp[size][size] = {0};

rep(i,size){
  dp[i][i] = wines[i]*size;
 }
repD(diagonal,size-1,1)
{
  rep(i,diagonal){
  	int yr = diagonal;
    int diff =size - yr;
    int j =i+diff;
    int m = wines[i]*yr + dp[i+1][j];
    int n = wines[j]*yr + dp[i][j-1];
    dp[i][j] = max(m,n);


  }
 
}
return dp[0][size-1];

}
int max_profit_TD(int wines[] , int *dp, int i,int j,int yr){

// Base case
	if(i> j) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	int a = wines[i] * yr + max_profit_TD(wines,dp,i+1,j,yr+1);
  	int b = wines[j] * yr + max_profit_TD(wines,dp,i,j-1,yr+1);

return dp[i][j]=max(a,b);


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
  
    int wines[]={2,3,5};
    int size = sizeof(wines)/sizeof(int);
   cout<< max_profit_BU(wines ,size)<<endl;
   int dp[size][100];
  
   cout<< max_profit_TD(wines ,dp,0,size-1,1);
  return 0;
}