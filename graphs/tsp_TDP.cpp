

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

int n=4;
int dist[10][10]=
{
{0,20,42,25},
{20,0,30,34},
{42 ,30,0,10},
{25,34,10,0}
};
int VISITED_ALL=(1<<n)-1;
int dp[16][4];
int tsp(int mask,int pos)
 {
 	if(mask==VISITED_ALL)
 	{
 		return dist[pos][0];
 	}

if(dp[mask][pos]!=-1)
{
	return dp[mask][pos];
}
int ans=INT_MAX;
  for(int city=0;city<n;city++)
  {
  	//set of unvisited nodes
  	if((mask &(1<<city))==0)
  	{
  		int temp=dist[pos][city]+tsp(mask|(1<<city),city);
  		ans=min(ans,temp);
  	 }
  }

  return dp[mask][pos]=ans;
  //return ans;
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
    repA(i,0,15)
     repA(j,0,4)
      dp[i][j]={-1};
    cout<<tsp(1,0);
    return 0;
}