#include<bits/stdc++.h>
 using namespace std;


int main()
{


int x;
cin>>x;
int mask=x&(x-1);
cout<<(x^mask)<<endl;//rightmost set bit
cout<<(x& -x)<<endl;
x|=x>>1;
x|=x>>2;
x|=x>>4;
x|=x>>8;
x|=x>>16;
int y=++x;
cout<<(y>>1);//leftmost set bit









  return 0;}
// x+(x-1)=y  where y is number with all bits right to leftmost 
//set bit in  number and x is the rwq answer
// 