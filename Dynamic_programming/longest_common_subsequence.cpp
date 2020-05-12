

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
int lcsubsequence(string s1 ,string s2 ,int m ,int n){

if(m==0 or n==0)
	return 0;
int res=0;

if(s1[m-1]==s2[n-1]){

 return 1 + lcsubsequence(s1,s2,m-1,n-1);
   }

else{
 return max(lcsubsequence(s1,s2,m,n-1),lcsubsequence(s1,s2,m-1,n));
  }

}


int lcsubsequenceDP(string s1, string s2 , int m ,int n){

int dp[m+1][n+1]={0};

 repA(i,1,m){

 	repA(j,1,n){
 		if(s1[i-1] == s2[j-1]){
 			dp[i][j] = 1 + dp[i-1][j-1];
 		}
 		else{

 			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
 		}
          
 	}

 }
 
  // lcs is stored in dp[m][m]
    int index = dp[m][n];
    char res[index+1];
    res[index] = '\0';
    int i=m,j=n;
   
   while(i> 0 && j>0){

    if(s1[i-1] == s2[j-1]){
    	res[index-1] = s1[i-1];
    	i--;j--;index--;
    }
    else if(dp[i-1][j] > dp[i][j-1])
        i--;
    else 
        j--; 	
    	
    }

  cout<<"Longest Common subsequence is "<<res<<endl;

return dp[m][n];

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
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.size(),n=s2.size();
    //cout<<lcsubsequence(s1,s2,m,n)<<endl;
    cout<<lcsubsequenceDP(s1,s2,m,n);

    return 0;
}