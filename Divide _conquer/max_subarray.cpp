#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll max(ll a,ll b,ll c)
{
    return max(max(a,b),c);
}
ll max_cross_sum(ll a[],ll s,ll mid,ll e)
{
 ll l_max=LLONG_MIN;ll r_max=LLONG_MIN;
 ll sum=0;
 for(ll i=mid;i>=s;i--)
 {
     sum+=a[i];
     if(sum>l_max)
      l_max=sum;

 }
 sum=0;
 for(ll i=mid+1;i<=e;i++)
 {
     sum+=a[i];
     if(sum>r_max)
     r_max=sum;

 }
 return l_max+r_max;
}

ll max_subarray(ll a[],ll s,ll e)
{
    //base case -when only 1 Element max_subarray sum is element itself
  if(s==e)
   return a[s];

 ll mid=(s+e)/2; //mid to divide the array

 //recursive case- returns the max of max_subarray sum in left ,right and and array containing mid
return max(max_subarray(a,s,mid-1),max_cross_sum(a,s,mid,e),max_subarray(a,mid+1,e));

}
int main() {

    ll T,N;cin>>T;//Testcases
    while(T--)
    {
      cin>>N; //size of array
      ll *a=new ll[N];
      for(ll i=0;i<N;i++)
      cin>>a[i]; //input array
      cout<<max_subarray(a,0,N-1);
    }
    return 0;
}
