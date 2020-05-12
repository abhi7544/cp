#include<bits/stdc++.h>
 using namespace std;

void binary_search(int a[],int key,int low,int high)
{
 int mid=(high-low)/2+low;
    if(low>=high)
   {
       cout<<"Not found";
       return;
   }
   if(a[mid]==key)
   {
       cout<<"found"<<key<<"at"<<mid;
       return;
   }

  else if(key>a[mid])
  {
      binary_search(a,key,mid+1,high);
  }
  else
  {
      binary_search(a,key,low,mid-1);
  }

}
int main()
{

int a[10]={1,4,5,6,4,2,8,9,0,10};
int n=sizeof(a)/sizeof(a[0]);
sort(a,a+n);
int T;
cin>>T;
while(T--)
{
int key;cin>>key;

binary_search(a,key,0,n-1);
}

return 0;}
