

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

class Edge{ 
public:
  int src;
  int dest;
  int weight;	

};
class Set{
 public:
    int rank;
    int parent;	
};

bool cmp(Edge e1 ,Edge e2){
 return e1.weight < e2.weight;
};

int find(Set *set , int i) {
	if(set[i].parent != i){
		set[i].parent=find(set,set[i].parent);
	}
	return set[i].parent;
}

void Union(Set *set,int v1,int v2) {
	int v1_root = find(set,v1);
	int v2_root = find(set,v2);
	set[v1_root].rank < set[v2_root].rank ? set[v1_root].parent=v2_root : set[v2_root].parent=v1_root;
	if(set[v1_root].rank == set[v2_root].rank ) {
     set[v2_root].parent=v1_root;
     set[v1_root].rank++; 

	}
}

void Kruskals(Edge *input,int n,int e){
	sort(input,input+e,cmp);
	Edge *output = new Edge[n-1];
    Set *set =new Set[n];
    rep(i,n){
 	set[i].rank=0;
 	set[i].parent=i;
 }
int counter=0,i=0;
while (counter< n) {
  Edge currentEdge = input[i];
  int sourceParent=find(set,currentEdge.src);
  int destinationParent=find(set,currentEdge.dest);
  if(sourceParent ! = destinationParent){
  	output[counter]=currentEdge;
    cout<< output[counter].src << " "<<output[counter].dest<<endl;
  	Union(set,sourceParent,destinationParent);
   cout<<" counter = "<<counter<<endl;
  counter++;
  }
  i++;
  }

  for(int i = 0 ;i < n ;i++) {
  	Edge x = output[i]; 
   cout<<x.src<<"----"<<x.weight<<"----"<<x.dest<<endl;
   }
}


int main(){    
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("/home/abhishek/Downloads/Algorithms/input.txt", "r", stdin);
    freopen("/home/abhishek/Downloads/Algorithms/output.txt", "w", stdout);
    #endif	
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,e;
    cin>>n>>e;
    Edge *input=new Edge[e];
    for(int i=0;i<e;i++) {
    int s,d,w;
    cin>>s>>d>>w;
    input[i].src=s;
    input[i].dest=d;
    input[i].weight=e;
  }

  Kruskals(input,n,e);
    return 0;
    
}