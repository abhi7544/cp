/*
easy to code
less memory 
solve specific not like segment

pre-requisite 

-N-2's complement left of rightmodt set bit are flipped
N & -N gives rightmost set bit
N -(N & -N) removes rightmost bit

bit[i]= ans of range(L,R)
 L=i-2^r+1 
 R=i
 r-pos of rightmost set bit
 (i,i) for odd i
 (1,i) for pow of 2
 (i-1,i)  other even
 build- N*log(N)
 query  
 - 1 to i  remove rightmost set bit 
 0 4 6 7 
 1 to 7 sum

 update-logN  i=i+(i &-i) add to all indices
 as all i contain i old 
 ex-
BIT 3      8      4     14     3
    1      2      3     4      5
   (1,1)  (1,2) (3,3) (1,4)  (5,5)
arr 3       5     4     2      3

query(5) (5,5)+(1,4)  
        i-  5     4   
        i=i-(i&-i)
indexing from 1
*/



#include <bits/stdc++.h>
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=n;++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
int  gcd(int a, int b){if (b!= 0) return gcd(b,a%b);else return a;}
int exp(int a ,int b){if(b==0)return 1; int ans=exp(a,b/2);ans*=ans; if(b&1) return a*ans; return ans;}
    

   

using namespace std;
using ll = long long;
int a[1000];

int BIT[1000]={0};

void update(int i,int val,int n)
{
     while(i<=n)
     {
      BIT[i]=max(BIT[i],val);
      i+=(i&-i);
     }
    
}

int query(int i)
{
	int ans=0;
	while(i>0)
	{
      ans=max(BIT[i],ans);
      i-=(i&(-i));
	}
return ans;
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
    int n;cin>>n;
   
    for(int i=1;i<=n;i++)
    {
  	cin>>a[i];
    update(i,a[i],n);
  
     }

    int q;cin>>q;
    while(q--)
    {
    	int ind;
    	cin>>ind;
    
    	cout<<query(ind)<<endl;
    }

    
    return 0;
}
