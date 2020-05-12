#include<bits/stdc++.h>
 using namespace std;

 void tower_of_hanoi(int n,char src,char hlp,char dst)
 {
     if(n==0)return;
     tower_of_hanoi(n-1,src,dst,hlp);
     cout<<"Move"<<n<<"th"<<src<<"to"<<dst<<endl;
     tower_of_hanoi(n-1,hlp,src,dst);


 }

int main()
{

int n;cin>>n;
tower_of_hanoi(n,'A','B','C');
return 0;

}
