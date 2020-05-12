

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

int maxProfit(int *priceofEachLen, int totalLen ,int *dp){

if(totalLen == 0) return 0;
int best =INT_MIN;
if(dp[totalLen]!=-1)
	return dp[totalLen];
 repA(len,1,totalLen){
 	int profit= priceofEachLen[len] + maxProfit(priceofEachLen,totalLen -len,dp);
    best = max(best,profit);
 }

return dp[totalLen]=best;

}

int maxProfit_BU(int *priceofEachLen,int totalLen,int *dp){
	rep(i,totalLen+1)
	dp[i]=0;

	repA(len,1,totalLen){
      int best = 0;
		repA(cut,1,len){
        best = max(best,priceofEachLen[cut] + dp[len - cut]);

		}
		dp[len] = best;
	}
	return dp[totalLen];
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
    int *priceofEachLen,*dp;
    int totalLen;
    cin>>totalLen;

    priceofEachLen = new int[totalLen+1];
    dp = new int [totalLen+1];

    repA(eachPrice,1,totalLen){
    	cin>>priceofEachLen[eachPrice];
    }
    rep(i,totalLen+1){
    	dp[i]=-1;
    }

   cout<<maxProfit(priceofEachLen,totalLen,dp)<<endl;
   cout<<maxProfit_BU(priceofEachLen,totalLen,dp);

    return 0;
}