

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

class Graph
{
 list<int> *l;
 int V;
 public:
   
     Graph(int V )
     {
      this->V=V;
      l=new list<int>[V];
     }
 	void addEdge(int u,int v)
 	{
 		l[u].push_back(v);
 		l[v].push_back(u);

 	}

 	bool is_tree()
 	{
     bool *visited=new bool[V];
     int *parent=new int[V];
      for(int i=0;i<V;i++)
      {
         visited[i]=false;
         parent[i]=i;
      }	
     
     int src=0;
     queue<int> q;
     q.push(src);
     visited[src]=true;
     while(!q.empty())
     {
      int node=q.front(); 	
      q.pop(); 
       
       for(auto nbr:l[node])
       {
      
       	if(visited[nbr] and nbr !=parent[node] )
       		return false;
       	else if(!visited[nbr])
       	 {
       	 	 	parent[nbr]=node;
        	 	visited[nbr]=true;
                q.push(nbr);
       	 }

       }

       }
     return true;  


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
    Graph g(4);
    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(0,2);
    //g.addEdge(2,3);

if(!g.is_tree())
cout<<"Not a tree";
else
cout<<"Yes a tree";

    return 0;
}