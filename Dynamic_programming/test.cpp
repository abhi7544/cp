

#include <bits/stdc++.h>
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
int  gcd(int a, int b){if (b!= 0) return gcd(b,a%b);else return a;}
int exp(int a ,int b){if(b==0)return 1; int ans=exp(a,b/2);ans*=ans; if(b&1) return a*ans; return ans;}
    
/* problem https://kutt.it/VdcA80  */ 

using namespace std;
using ll = long long;
#define vec vector<int>   
//lower_bound similiar function
int firstindex_not_less_than_k(vec active_list , int key,int seq_index){
	int high = seq_index;
	int low  = 0;
	int mid;
	while(high > low + 1){
     mid = low + (high - low)/2;
     if( key > active_list [mid])
     	low = mid;
     else if( key < active_list[mid])
        high = mid;


	}

	if(low > key)
		return low;
	else 
		return high;


}

int lis (vec seq , vec active_list){

  int n = seq.size();
  if(n <=1)
  	return n;
  //start the first list with its end element
  active_list[0] = seq [0];
  int seq_index=0;
  //start from next number in sequence

  vec s(seq.begin()+1,seq.end());

  for(auto x : s){
  
  // smallest of all active list of end_elememt 
  
   if( x  < active_list[0])
   	active_list[0] = x;

  //greatest of all active list of end_element
   else if( x > active_list[seq_index ])
   	active_list[++seq_index] = x;

   else{
  
   //	int place =lower_bound(active_list.begin(), active_list.begin()+seq_index+1,x) - active_list.begin();
   	int place =firstindex_not_less_than_k(active_list,x,seq_index);
   	active_list[place]=x;
 

   }


  }



return seq_index+1;
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
    vec seq;
    int n;cin>>n;
    rep(i,n){
    	int temp;cin>>temp;
    	seq.push_back(temp);
    }
    vec active_list(n);
    cout<<lis(seq,active_list);
    return 0;
}