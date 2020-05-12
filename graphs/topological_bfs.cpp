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






     
     void topological()
     {
      queue<T> q;
      
      map<T,bool> visited; 
      map<T,int> indegree;
        for(auto l:adjlist)
        {
        	indegree[l.first]=0;
        }

       
       for(auto l: adjlist)
       {
            T node=l.first;
            for(auto nbr:adjlist[node])
                 {
                 	int s=nbr.first;
                 	if(!visited[s])
                 	{
                 		indegree[s]++;
                 	}
                 }
        }


   for(auto x:indegree)
     {
     	if(x.second==0)
     	{
     		q.push(x.first);
     	}
     }

     while(!q.empty())
      {
       T node=q.front();
       q.pop();
       cout<<node<<" ";
         for(auto nbr:adjlist[node])
            {
            	T t=nbr.first;
            	indegree[t]--;
            	if(indegree[t]==0)
            		q.push(t);
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


    g.addEdge(1,2,0,false);
//    g.addEdge(1,3,0,false);
    g.addEdge(1,4,0,false);
    g.addEdge(0,2,0,false);

    g.addEdge(2,3,0,false);
    g.addEdge(2,5,0,false);

    g.addEdge(4,5,0,false);
    g.addEdge(3,5,0,false);
   


    
   





// g.addEdge("Delhi","kolkata",17,false);
// g.addEdge("Delhi","Mumbai",10,false);
// g.addEdge("Mumbai","kolkata",15,false);
// g.addEdge("Banglore","kolkata",19,false);
// g.addEdge("Banglore","kolkata",20,false);
// g.addEdge("Banglore","Mumbai",40,false);
 g.printGraph();cout<<"\n";
//g.bfs(0);cout<<"\n";
//g.dfs();
 g.topological();
return 0;

}
