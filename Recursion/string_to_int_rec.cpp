#include<bits/stdc++.h>
 using namespace std;
int Toint(string s,int n)
{
    if(n==1)
        return s[0]-'0';


        return (10*(Toint(s,n-1))+s[n-1]-'0');

}

int main()
{
string s;cin>>s;
int n=s.size();
cout<<Toint(s,n);

return 0;}
