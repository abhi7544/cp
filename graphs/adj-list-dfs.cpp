#include<bits/stdc++.h>
 using namespace std;
 class Graph
 {
 int V,f,s;

 list<int > *adjlist;
 map<int,int> vertex_to_ft;
 public:
 Graph(int v )
 {   s=0;
     f=0;
     V=v;
     adjlist=new list<int>[V];

 }
 void addEdge(int  a,int  b,bool bidir=false)
 {
    adjlist[a].push_back(b);
     if(bidir)
   {
    adjlist[b].push_back(a);
   }
 }

 void print()
 {
 for(int i=0;i<V;i++)
 {
   cout<<i<<"->";
   for(int node:adjlist[i])
    cout<<node<<",";
    cout<<endl;
   }
 }
void topsort( map<int, int>::iterator itr)
{
      do{
   itr--;

       cout << itr->second<<"-->";

      }while(itr  != vertex_to_ft.begin());
}

void dfs(int src)
{  cout<<"DFS traversal"<<endl;
    int *visited=new int[V]{false};
    int *st=new int[V]{0};
    int *ft=new int[V]{0};
    dfsutils(src,visited,st,ft);

    cout<<"\nStarting & finish time of each vertex"<<endl;
    for(int j=0;j<V;j++)
    {
        cout<<"ST of"<<j<<" ="<<st[j]<<endl;
        cout<<"FT of"<<j<<" ="<<ft[j]<<endl;
    }
     map<int, int>::iterator itr;
    cout << "\nThe map of node and ft is : \n";
    cout << "\tnode \tfinishing time\n";
    for (itr = vertex_to_ft.begin(); itr != vertex_to_ft.end(); ++itr) {
        cout << '\t' << itr->second
             << '\t' << itr->first<< '\n';
    }

    cout << endl;

     topsort(itr);

     // topsort(src,end_t);
  }

void dfsutils(int src,int visited[],int st[],int ft[])
{
    visited[src]=true;
    st[src]=++s;

    cout<<src<<" ";
    list<int>::iterator it;
    if(!adjlist[src].empty())
    {
    for(it=adjlist[src].begin();it!=adjlist[src].end();it++)
     {
        if(!visited[*it])dfsutils(*it,visited,st,ft);
     }
    }

      ft[src]=++s;
         vertex_to_ft.insert(pair<int, int>(s,src));


}
 };


int main()
{

Graph g(8);
    g.addEdge(1,0);
    g.addEdge(2,1);
    g.addEdge(3,1);
    g.addEdge(5,2);
    g.addEdge(6, 3);
    g.addEdge(5,4);
    g.addEdge(5,2);
    g.addEdge(6,4);
    g.addEdge(7,5);
    g.addEdge(7,6);



    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.dfs(7);
return 0;}
