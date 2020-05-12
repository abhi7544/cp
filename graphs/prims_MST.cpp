

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
int findMinVetex(int *weight ,bool *visited , int v ){
     int minVertex =-1;
     repA(i,0,v-1){
     	if( !visited[i] and  (minVertex==-1 or weight[i] < weight[minVertex]))
     		minVertex =i;
     }
  return minVertex;

	}

class Graph{
public:
	int v;
	list<pair<int, int> > *adj;
	Graph(int v) {
		this->v=v;
		adj= new list<pair<int, int> >[v];
	}
	void addEdge(int u,int v, int w) {
		adj[u].push_back(make_pair(v,w));
	    adj[v].push_back(make_pair(u,w));

	}

	

	void Prims() {
      bool *visited = new bool[v];
      int  *parent = new int[v];
      int  *weight = new int[v];
      rep(i,v){
      visited[i]=false;
      weight[i]=INT_MAX;
       }
      parent[0] = -1;
      weight[0] = 0;
      rep(i,v){
      	int minVertex = findMinVetex( weight ,visited,v);
      	visited [minVertex] =true;
      	for(auto nbr :adj[minVertex]){
      		if(!visited[nbr.first]){
      			 if(nbr.second < weight[nbr.first]){
      			 	parent[nbr.first] = minVertex;
      			 	weight[nbr.first] = nbr.second;
      			 }
      		}
      	}

      } 
      repA(i,1,v-1)
      {
      	cout<<i<<"--"<<parent[i]<<" weight "<<weight[i]<<endl;
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
    int n,e;
    cin>>n>>e;
    Graph g(7);
    rep(i,e){
    	int u,v,w;
    	cin>>u>>v>>w;
        g.addEdge(u ,v ,w);
    }

  g.Prims();
    return 0;
}