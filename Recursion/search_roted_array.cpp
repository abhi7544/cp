#include<bits/stdc++.h>
 using namespace std;
int search_key(int a[],int s,int e,int key)
{

    int mid=(s+e)/2;
    if(a[mid]==key)
        return mid;

    if(a[s]<=a[mid])
    {
        if(key>=a[s] && key<=a[mid])

        {
         return search_key(a,s,mid-1,key);
        }
        else
          return search_key(a,mid+1,e,key);
    }

    if(key>=a[mid]&& key<=a[e])
    {
        return search_key(a,mid+1,e,key);
    }
    else
     return search_key(a,s,mid-1,key);

}

int main()
{

int *a;
int n;cin>>n;
a=new int[n];
int key;

for(int i=0;i<n;i++)cin>>a[i];
cout<<endl;
cout<<"Enter key to search";cin>>key;

cout<<search_key(a,0,n-1,key);

  return 0;}
