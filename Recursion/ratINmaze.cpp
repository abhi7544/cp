#include <iostream>
#define s 1001
using namespace std;
void print_sol(int sol[][s],int m,int n)
{
    for(int i=1;i<=m;i++)
    { for(int j=1;j<=n;j++)
      { cout<<sol[i][j]<<" ";
      }
       cout<<endl;
    }
}

bool PathInMaze(char maze[s][s],int sol[s][s],int i,int j,int m ,int n)
{
    //base case
    if(i==m && j==n)
    {
        sol[i][j]=1;
        print_sol(sol,m,n);cout<<endl;
        return true;
    }

    if(i>m || j>n ||maze[i][j]=='X')return false;//if position is out of grid or blocked no path through it

    sol[i][j]=1;
    //recursive case
   if(PathInMaze(maze,sol,i,j+1,m,n))return true;//check for right path
   if(PathInMaze(maze,sol,i+1,j,m,n))return true;//check for doenword path if horizontal doesnot exist

   sol[i][j]=0;//if none of the above direction satisfy  backtrack

   return false;


}
int main() {
    int m,n;cin>>m>>n;
    char maze [s][s];
    int sol[s][s]={0};
    for(int i=1;i<=m;i++)
     for(int j=1;j<=n;j++)cin>>maze[i][j];
    if(!PathInMaze(maze,sol,1,1,m,n))
    cout<<-1;
    cout<<endl;
