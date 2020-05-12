 #include<bits/stdc++.h>
 using namespace std;


void bubble_sort(int a[],int n)
{
if(n==1)return;

for(int i=0;i<=n-2;i++)
{
    if(a[i]>a[i+1])
    {
        a[i]=a[i]^a[i+1];
        a[i+1]=a[i]^a[i+1];
        a[i]=a[i]^a[i+1];

    }

}

bubble_sort(a,n-1);
}


void bubble_sort2(int a[],int i,int n)
{
   if(n==1)return;
   if(i==n-1)
       {
         return bubble_sort2(a,0,n-1);
       }
   if(a[i]<a[i+1])
    {
        a[i]=a[i]^a[i+1];
        a[i+1]=a[i]^a[i+1];
        a[i]=a[i]^a[i+1];

    }

    bubble_sort2(a,i+1,n);
    return;
}


int main()
{
int a[]={5,4,3,2,1};
int n=sizeof(a)/sizeof(a[0]);

bubble_sort(a,n);
for(int i=0;i<n;i++)cout<<a[i]<<"- ";
bubble_sort2(a,0,n);
for(int i=0;i<n;i++)cout<<a[i]<<", ";

  return 0;}
