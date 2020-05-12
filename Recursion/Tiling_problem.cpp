#include<bits/stdc++.h>
 using namespace std;
 /*
 Tiling Problem
Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.
Examples:

Input n = 3
Output: 3
Explanation:
We need 3 tiles to tile the board of size  2 x 3.
We can tile the board using following ways
1) Place all 3 tiles vertically.
2) Place first tile vertically and remaining 2 tiles horizontally.
3) Place first 2 tiles horizontally and remaining tiles vertically

Input n = 4
Output: 5
Explanation:
For a 2 x 4 board, there are 5 ways
1) All 4 vertical
2) All 4 horizontal
3) First 2 vertical, remaining 2 horizontal
4) First 2 horizontal, remaining 2 vertical.00000000
5) Corner 2 vertical, middle 2 horizontal
tilingproblem
i
 */
 int dp[10000];
 int ways(int n)
 {


     if(dp[n]==-1)
     {
         if(n<=1)
          dp[n]=n;

         else
            dp[n]=ways(n-1)+ways(n-2);

              }



       return dp[n];

 }


int main()
{
int n;
cin>>n;
memset(dp,-1,sizeof(dp));

cout<<ways(n);

  return 0;}
