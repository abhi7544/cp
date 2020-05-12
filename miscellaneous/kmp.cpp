

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

void create_lps(int *lps,string pat)
 {

 int m=pat.size();
 memset(lps,0,sizeof(lps));
 int j=0,i=1;
//j is frst mismatch index
 while(i<m)
 {
    //when match 
    if(pat[j]==pat[i])
    {
        j++;
        lps[i]=j;
        i++;
    }
    //
    else if(pat[j]!=pat[i] and j!=0)
    {
        j=lps[j-1];

    }

    else
    {
        lps[i]=0;
        i++;
    }

 }

 }


bool kmp(string text,string pat)
{

int s=pat.size();

//Auxillary array for lpsfix suffix match array 
int *lps=new int[s];

//creating
create_lps(lps,pat);

int n=text.size();
rep(i,pat.size());
int i=0,j=0;

while(i<n)
 {
    if(pat[j]==text[i])
    {
        i++;j++;
        if(j==s)
            {cout<<"pattern found at"<<(i-j)<<"\n";
              j=lps[j-1];
               }
    }

    else if(pat[j]!=text[i] and j!=0)
     {
      j=lps[j-1];
     } 

    else
    {
     i++;

    }
 }
 
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
    string text,pat;
    cin>>text;
    cin>>pat;
    
    kmp(text,pat);
    return 0;
}