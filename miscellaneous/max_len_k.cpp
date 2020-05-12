#include<bits/stdc++.h>
using namespace std;

int max_len_k(int *a,int n,int k,int *ix,int *jx)
 {
 	int pre_sum=0;
 	int max_len=INT_MIN;
	unordered_map<int, int> presum; 
   for(int i=0;i<n;i++)
   {
   	pre_sum+=a[i];
   	if (a[i] == k && max_len == 0) 
			max_len = 1; 
   	if(pre_sum==k)
   	  {max_len=max(max_len,i+1);
          *jx=i;
          *ix=0;
          }
      
    
		// Look for this sum in Hash table 
		if (presum.find(pre_sum-k) != presum.end()) { 
			// If this sum is seen before, then update max_len 
		
			if(i-presum[pre_sum-k] > max_len)
			{*jx=i;
            *ix=presum[pre_sum-k]+1;
            max_len=(i- presum[pre_sum -k]);
             }
		} 
		else { 
			// Else insert this sum with index in hash table 
			presum[pre_sum] = i; 
		} 


     }

  return max_len;
   }


 int main()
 {
 int a[]={1,-1,5,-2,8,3},k;
 int n =sizeof(a)/sizeof(int);
 int i,j;
 cin>>k;
 cout<<"Max length of subarray with sum "<<k<<" is"<<max_len_k(a,n,k,&i,&j)<<"\n";
 cout<<"Between "<<i<<" and "<<j;

 }
