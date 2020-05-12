#include<bits/stdc++.h>
 using namespace std;
int pivot(int a[],int n)
{
    int s=0,e=n-1,mid;
    while(s<=e)
    {
            mid=(s+e)/2;

        if(a[mid]>a[mid+1])
            return mid;


         if(a[mid-1]>a[mid])
                return mid-1;

          if(a[e]<a[mid])
           s=mid+1;
          else if(a[s]>a[mid])
            e=mid-1;


    }


}

int main()
{

int *a;
int n;cin>>n;
a=new int[n];

for(int i=0;i<n;i++)cin>>a[i];

cout<<pivot(a,n);

  return 0;}
