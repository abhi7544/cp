#include<bits/stdc++.h>
 using namespace std;
 class Graph
 {
 int V;

 list<int > *adjacent;
 public:
 Graph(int v )
 {
     V=v;
     adjacent=new list<int>[V];

 }
 void addEdge(int  a,int  b,bool bidir=true)
 {
    adjacent[a].push_back(b);
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
  }

 };


int main()
{

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

return 0;}
