#include<bits/stdc++.h>
 using namespace std;

void print_decreasing(int n)
{
    if(n==0)return;
    cout<<n<<" ";
   print_decreasing(n-1);


}
int main()
{
 int n;cin>>n;
 print_decreasing(n);

 return 0;}
