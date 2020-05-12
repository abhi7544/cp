#include<bits/stdc++.h>
 using namespace std;

 //counts the # of conf in which N-queen can be safe
 bitset<30> c,dl,dr; //bitsets to check safe queen along column(given column) ,left diagnol (row- col=const),rihgt diagnol(row+col=const)


 void solveNqueen(int n,int r,int &ans)
 {
    if(r==n)
    {
        ans++;
        return;
    }

    for(int j=0;j<n;j++)
    {
              //if the queen is safe

        if((!c[j])&&(!dl[r-j+n-1])&&(!dr[r+j]))
           {
              c[j]=dl[r-j+n-1]=dr[r+j]=1;//blocking to place any queen in same column ,along left diagnol ,along right diagnol ,setting bit
              solveNqueen(n,r+1,ans);//check for the next row
              c[j]=dl[r-j+n-1]=dr[r+j]=0;//control reaches here means previos row is not safe
                                        // unset the blocked cells
           }

    }

 }


int main()
{
 int n;
 cin>>n;
 int ans=0;//counts # of conf
 solveNqueen(n,0,ans);
 cout<<ans;
return 0;}
