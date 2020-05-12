

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
  

 	}
  bool is_DCG_helper(int src,bool *visited,bool *stack)
   {
    //visiting node
    visited[src]=true;
    stack[src]=true;
   for(auto nbr:l[src])
   {
    if(!visited[nbr])
       {
        bool cycle_mila=is_DCG_helper(nbr,visited,stack);
        if(cycle_mila)
         return true;
       }
       //nbr already visited does it form back edge check in stack
       else if(stack[nbr])
        return true;

   }

  // leaving back
    stack[src]=false;

    return false;
   }



bool is_DCG()
  {
    bool *visited=new bool[V];
    bool *stack=new bool[V];
for(int i=0;i<V;i++)
 { visited[i]=false;
    stack[i]=false;
 }
 return is_DCG_helper(0,visited,stack);
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
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(6,4);  
    if(g.is_DCG())
      cout<<"Directed cyclic Graph\n";
    else
      cout<<"Directed Acyclic graph";
    return 0;
}