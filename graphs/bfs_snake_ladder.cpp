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
     
     T bfs(T src,T dest)
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
      T node=dest;
       cout<<node<<"->";
        while(node!=src)
        {
          cout<<parent[node]<<"->";
          node=parent[node];
        }
       
      cout<<"\n";
     return dist[dest];
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
   int board[50]={0};
     board[2]=13;
     board[5]=2;
     board[9]=18;
     board[18]=11;
     board[17]=-13;
     board[20]=-14;
     board[24]=-8;
     board[25]=10;
     board[32]=-2;
     board[34]=-22;
    
    Graph<int> g;
   for(int i=0;i<=36;i++)
   {
     for(int dice=1;dice<=6;dice++)
      { 
       int j=i+dice;
       j=j+board[j];
       if(j<=36)
       g.addEdge(i,j,0,false);
        }
   }

    g.addEdge(36,36,0,false);

// g.addEdge("Delhi","kolkata",17,false);
// g.addEdge("Delhi","Mumbai",10,false);
// g.addEdge("Mumbai","kolkata",15,false);
// g.addEdge("Banglore","kolkata",19,false);
// g.addEdge("Banglore","kolkata",20,false);
// g.addEdge("Banglore","Mumbai",40,false);
//g.printGraph();
cout<<g.bfs(0,36);

return 0;

}
