#include<bits/stdc++.h>
 using namespace std;

 char spell[][10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
 void toWord(int n)
 {
     if(n==0)return;
     int temp=n%10;
     n=n/10;
     toWord(n);
     cout<<spell[temp]<<" ";

 }


int main()
{

 int n,T;
 cin>>T;
 while(T--)
 {cin>>n;;

 toWord(n);

 }






  return 0;}
