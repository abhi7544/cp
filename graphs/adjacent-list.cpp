

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

 #include<bits/stdc++.h>
 using namespace std;
 class Graph
 {
 int V;

 // Array of list for each vertex a list
 list<int > *adjacent;
 //dynamic as size known at runtime
 public:
 Graph(int v )
 {
     V=v;
     adjacent=new list<int>[V];

 }
 void addEdge(int  a,int  b,bool bidir=true)
 {
    adjacent[a].push_back(b);// in adjacentp[a] list b is added
     if(bidir)
   {
    adjacent[b].push_back(a);
   }
 }

 void print()
 {
 for(int i=0;i<V;i++)
 {
   cout<<i<<"->";
   for(int node:adjacent[i])
    cout<<node<<",";
    cout<<endl;
   }
 }

void bfs(int src)
{
    queue<int>q;
    cout<<"Bfs Traversal: ";
    bool *visited=new bool[V+1]{0};
    int *dist=new int[V+1];
    int *parent=new int[V+1];
    dist[src]=0;
    parent[src]=-1;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
      int node=q.front();
      q.pop();
      cout<<node<<" ";
     for(auto neighbor:adjacent[node])
     {
       if(!visited[neighbor])
       {
         q.push(neighbor);
         visited[neighbor]=true;
         dist[neighbor]=dist[node]+1;
         parent[neighbor]=node;
       }

     }
    }

    cout<<endl;int i;
    for( i=0;i<V;i++)
    {   if(i!=src)
        cout<<src <<"-->"<<i<<"shortest distance"<<dist[i]<<" "<<endl;
        int temp=i;
        while(temp!=-1 )
        {
            cout<<temp<<"->";
            temp=parent[temp];
        }
        cout<<endl;
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
    Graph g(6);
    g.addEdge(1,2);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,2);    
    g.addEdge(4,3);
    g.addEdge(2,3);    
    g.addEdge(3,5);
    g.print();    
    g.bfs(0);    
    return 0;
}