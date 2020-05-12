#include<bits/stdc++.h>
 using namespace std;

 //calculate # of config of placing n-queeen using bitmasking to  find the next row safe confg

int n,ans=0,DONE;//DONE -for rowmask to get DONE it has all col it indicates all col filled
void solveNqueen(int n,int rmask,int ld,int rd)
{
 if(rmask==DONE)
 {
 ans++;return;
 }
 int safe=DONE &(~( rmask|ld|rd));//generating next row safe connfig & DONE is to remove extra bits

 while(safe)
 {
     int p=safe&-safe;//gives the rightmost  set bit
     safe=safe-p;      //number without the set bit p

     solveNqueen(n,rmask|p,(ld|p)<<1,(rd|p)>>1);//blocking current diagnol blocked till now + diagnol corresponding to p
 }


}


int main()
{
  int c=1;
  while(c)
{cin>>n;//# of col n=4(say)
  DONE=(1<<n)-1;//-1111 { p=1<<N =1000  then  p-1=1111  }

  solveNqueen(n,0,0,0);
 cout <<ans<<endl;
 cout<<"enter 0 to exit";
 cin>>c;
 ans=0;
}

return 0;
}
