#include<bits/stdc++.h>
 using namespace std;

 template<typename T>
 class Graph
 {
   map<T,list<pair<T,int>>> adjlist;
   public:
       void addEdge(T u,T v,int wt,bool bidir)
       {   

           adjlist[u].push_back(make_pair(v,wt));
           if(bidir)
            adjlist[v].push_back(make_pair(u,wt));
       }

       void printGraph()
       {
       for(auto row:adjlist)
       {
         cout<<row.first<<"->";
         for(pair<T,int> ele :row.second)
            cout<<"("<<ele.first<<","<<ele.second<<")  ";
            cout<<endl;

       }
       }

     void dfs_helper(T src, map<T,bool> &visited)
       {

        cout<<src<< " ";
        visited[src]=true;
        for(auto nbr:adjlist[src])
        {
         T n=nbr.first;
         if(!visited[n])
           {
            dfs_helper(n,visited);
           }
        }

       }
     void dfs(T src)
       {
        map<T,bool> visited;
        for(auto p:adjlist)
        {
          T node=p.first;
          visited[node]=false;
        }
        dfs_helper(src,visited);
       }
     
     void bfs(T src)
     {
      
      queue<T> q;
      //dist ~visited
      map<T,int> dist; //int for shortest distance
      map<T,T> parent;
    for(auto node:adjlist)
    {
        T str=node.first;
        dist[str]=INT_MAX;
    }

      q.push(src);
      dist[src]=0;

      while(!q.empty())
      {
        T node=q.front();
        q.pop();
        cout<<node<<"  ";

        for(auto nbr :adjlist[node])
        {
          if(dist[nbr.first]==INT_MAX)
          {
            q.push(nbr.first);
            parent[nbr.first]=node;
           dist[nbr.first]=dist[node]+1;
            }

          }

      }

    cout<<endl;
    //print distance to each node
    for(auto curr:adjlist)
      {
       T node=curr.first;
       cout<<"\nshortest distance from "<<src<<" to "<<node<<" is "<<dist[node]<<endl;
       cout<<node<<"->";
        while(node!=src)
        {
          cout<<parent[node]<<"->";
          node=parent[node];
        }
       
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

// Graph<string> g;
    Graph<int> g;


    g.addEdge(1,2,0,true);
    g.addEdge(1,0,0,true);

     g.addEdge(0,3,0,true);

    g.addEdge(4,5,0,true);    
    g.addEdge(4,3,0,true);

   
    g.addEdge(3,2,0,true);


// g.addEdge("Delhi","kolkata",17,false);
// g.addEdge("Delhi","Mumbai",10,false);
// g.addEdge("Mumbai","kolkata",15,false);
// g.addEdge("Banglore","kolkata",19,false);
// g.addEdge("Banglore","kolkata",20,false);
// g.addEdge("Banglore","Mumbai",40,false);
//g.printGraph();cout<<"\n";
//g.bfs(0);cout<<"\n";
g.dfs(0);

return 0;

}
