

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
	int src,dest,weight;
};

class Graph{
  public:
  int v,e;
  Edge *edge;
  Graph(int v, int e){
  	this->v =v;
  	this->e =e;
  	edge = new Edge[e];
  }
  void addEdge(int u ,int v ,int w ,int count){
  	edge[count].src = u;
  	edge[count].dest = v;
  	edge[count].weight =w;
  }
  void BellmanFord(int src){
  	int distance[v];
  	rep(i,v) {
  		if(i==src)distance[i]=0;
  		else distance[i]=INT_MAX;

  	}
  	//Relaxation code
   repA(i,1,v-1){
   	 rep(j,e){
   	 	int src = edge[j].src;
   	 	int dst = edge[j].dest;
   	 	int wt = edge[j].weight;
   	 	// Relaxtion check
   	 	if(distance[src] !=INT_MAX and distance[src] + wt < distance[dst]){
   	 		distance[dst] = distance[src] +wt;

   	 	}
   	 }
   }
// check negative weight cycle

 rep(j,e){
   	 	int src = edge[j].src;
   	 	int dst = edge[j].dest;
   	 	int wt = edge[j].weight;
   	 	// Relaxtion check
   	 	if(distance[src] !=INT_MAX and distance[src] + wt < distance[dst]){
   	 		cout<<"Graph has negative cycle";
          return;
   	 	}
   	 }
    rep(i,v){
    	cout<<i<<" ---  " <<distance[i]<<endl;
    }

    }
};

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
    
int v,e;cin>>v>>e;
Graph g(v,e);
rep(i,e){
	int u,v,w;
	cin>>u>>v>>w;
	g.addEdge(u,v,w,i);
}

g.BellmanFord(0);

    return 0;
}