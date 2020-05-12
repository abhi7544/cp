#include<bits/stdc++.h>
 using namespace std;

 template<typename T>
 class Graph
 {
   map<T,list<pair<T,int>>> adjlist;
   public:
       void addEdge(T u,T v,int wt,bool bidir=true)
       {   

           adjlist[u].push_back(make_pair(v,wt));
  
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
    
      void Djistra(T src)
      {
        unordered_map<T,int> dist;
         for(auto d:adjlist)
         {
          dist[d.first]=INT_MAX;
         }

       dist[src]=0;
       set<pair<int,T>> s;
       s.insert(make_pair(dist[src],src));
       while(!s.empty())
       {
          auto p=*(s.begin());
          T node=p.second;
          int pathFromSource=p.first;
          s.erase(s.begin());
          for(auto nbr:adjlist[node])
          {
            T v=nbr.first;
            int wt=nbr.second;
             if(pathFromSource+wt<dist[v])
             {
              auto f= s.find(make_pair(dist[v],v));
              if(f!=s.end())
              {
                s.erase(f);
              }
              dist[v]=wt+pathFromSource;
              s.insert(make_pair(dist[v],v));

             }

          }

       }
       for(auto x:dist)
       {
        cout<<x.first<<" "<<x.second<<" distance from "<<src<<endl; 
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

Graph<string> g;
    // Graph<int> g;


    // g.addEdge(1,2,0,true);
    // g.addEdge(1,0,0,true);

    //  g.addEdge(0,3,0,true);

    // g.addEdge(4,5,0,true);    
    // g.addEdge(4,3,0,true);

   
    // g.addEdge(3,2,0,true);


g.addEdge("Delhi","kolkata",17,false);
g.addEdge("Delhi","Mumbai",1,false);
g.addEdge("Mumbai","kolkata",15,false);
g.addEdge("Banglore","kolkata",19,false);
g.addEdge("Banglore","Mumbai",33,false);
g.addEdge("Banglore","surat",1,false);
g.addEdge("Delhi","surat",34,false);


g.printGraph();

g.Djistra("Delhi");
return 0;

}
