

#include <bits/stdc++.h>
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
int  gcd(int a, int b){if (b!= 0) return gcd(b,a%b);else return a;}
int exp(int a ,int b){if(b==0)return 1; int ans=exp(a,b/2);ans*=ans; if(b&1) return a*ans; return ans;}
#define um  unordered_map   
/*
You are given a linear equation y = mx + c, and an array A of n elements. Count the number of ordered pairs (i,j) where i!=j, such that point (Ai, Aj) satisfies the given linear equation.

Input Format
2<=n<=2*10^5
-10^9 <= Ai, m, c<= 10^9
First line contains 3 integers, n, m and c. Next line contains n integers, denoting the elements of array A.
*/
   

using namespace std;
using ll = long long;

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
    ll n,m,c;
    cin>>n>>m>>c;
    um<ll,int> map;
    int *a=new int[n];
  rep(i,n)
  {
   cin>>a[i];
   map[a[i]]++;
  }
  int ans=0;

   rep(i,n)
   { int x=a[i];
    int y=m*x+c;
    if(map.find(y)!=map.end())
     {
     ans+=map[y];
     }
     if(y==x)
     {
     	ans--;
     }
   } 
    cout<<ans<<endl;
    return 0;
}