#include <bits/stdc++.h>
using namespace std;
using ll= long long;

ll count_the_triplets(ll *arr , int  n){

 sort(arr,arr+n);
 ll count=0;

int c = n-1;

//while(c >=2){
 // int b = c-1;
// int a = 0;
//  while(a < b){
 	// int sum =arr[a] + arr[b];z 
 	// if(sum == arr[c])
 // 		count++;
 	
 // 	else if(sum < arr[c])
 // 		a++;
 // 	else
 // 		b--;
 // }

//c--;	
//}

return count;
}

int main() {
	   #ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("/home/abhishek/Downloads/Algorithms/input.txt", "r", stdin);
	    freopen("/home/abhishek/Downloads/Algorithms/output.txt", "w", stdout);
	    #endif	
	    ios::sync_with_stdio(0);
	    cin.tie(0);
	    cout.tie(0);
	  
	ll T;cin>>T;
	while(T--){
	    ll n;cin>>n;
	    ll *a = new ll[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    cout<<count_the_triplets(a,n)<<"\n";
	}
	return 0;
}