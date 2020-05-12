
#include<bits/stdc++.h>
#define for(i,c,n) for(int i=c;i<=n;i++)
using namespace std;

bool isPossible(int arr[],int n,int  m,int curr_min)
 {
 	int stu_used=1;
 	int page_reading=0;
 	 	for(i,0,n-1)
 	 	{
 	 		//when page read is greater than max pages allowed aloocate to other stu
 	 		if(page_reading+arr[i]>curr_min)
 	 			{
 	 				//next student
 	 				stu_used++;
 	 				page_reading=arr[i];//allocation start with next book
 	 				if(stu_used>m)
 	 					return false;
 	 			}
 	 			//if it is less  than max page allowed keep on adding 
 	 			else
 	 			{
 	 				page_reading+=arr[i];
 	 			}
 	   }

 	return true;


 }

int findPage(int arr[],int n,int m)
{
 int sum=0;
 //M>N
 if(m>n)
 	return -1;
 //count total no. pages
 for(i,0,n-1)
 	sum+=arr[i];
//creating search space (range)
// s......mid.......e
 int s=arr[n-1]; //max #pages aloocated -> student >=max # pages in books
 int e=sum;
 int ans=INT_MAX;
 cout<<s<<" "<<e<<endl;
  while(s<=e)
  {
  	int mid=(s+e)/2;
  	 if(isPossible(arr,n,m,mid))
  	 {
  	 
  	 	ans=min(ans,mid);
  	 	e=mid-1;
  	 		}
  	 else
  	 {
  	 	s=mid+1;
  	 }


  }
  return ans;
}

 int main()
 {
 int t;
 cin>>t;
   while(t--)
   {
   	int n,m;
   	cin>>n>>m;
   	int arr[1000];
   	for(i,0,n-1)
   		cin>>arr[i];
   	cout<<findPage(arr,n,m)<<"\n";

   }
return 0;
 }