#include<bits/stdc++.h>
 using namespace std;

/*
find the valid configuration of N-queens in a board
in valid configuration all the queens are safe
a safe queen is one which does not have any other queen in the same row and column
and in all the diagnols of the respective queen

*/
bool checksafe(int board[][100],int i,int j,int n)
{
    //check for the same column
  for(int row=0;row<i;row++)
  {
      if(board[row][j]==1)return false;
  }
//left upper diagnal
int x=i;
int y=j;

while(x>=0 &&y>=0)
{
    if(board[x][y]==1)return false;
    x--;
    y--;
}
//right upper diagnal
 x=i;
 y=j;

while(x>=0 &&y<n)
{
    if(board[x][y]==1)return false;
    x--;
    y++;
}
return true;

}

void print(int board[][100],int n)
{
    for(int i=0;i<n;i++)
     {for(int j=0;j<n;j++)
     {
         if(board[i][j]==1)
            cout<<"Q";
           else
              cout<<"-";

       }
       cout<<endl;
     }
     cout<<endl;
}



bool solveNqueen(int board[][100],int i,int n)
{//base case
  if(i==n)//succesfully placed all queens (0 1 2 ...n-1)
   {
         cout<<"printing... ";
       print(board,n);//prints the valid config
       cout<<endl;
       return false;
   }
       for(int j=0;j<n;j++)
       {
        if(checksafe(board,i,j,n))//check if current position is safe
       {
        board[i][j]=1;    // if yes places a queen assuming right place
        bool nextqueenplacable=solveNqueen(board,i+1,n);//check for  rest config if true return true;for the next row if possible to place queen in any cell
         if(nextqueenplacable)
            {return true;
            }
            //if not right place
            board[i][j]=0;//backtrack;

         }

       }

return false;
}

int main()
{


//make a board
int board[100][100]={0};
int n; //# of rows in board
cin>>n;

solveNqueen(board,0,n);//find config starting from oth row
return 0;}
