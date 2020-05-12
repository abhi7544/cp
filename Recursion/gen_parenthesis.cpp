

#include<bits/stdc++.h>
#define MAX 50
using namespace std;
void gen_parenthesis(int pos,int n,int open ,int close)
{
    static char s[MAX];
    if(close==n)
   {
      cout<<s<<"\n";
      return;
   }
   else
   { if(open>close)
    {
        s[pos]=')';
        gen_parenthesis(pos+1,n,open,close+1);
    }
    if(open<n)
    {
        s[pos]='(';
        gen_parenthesis(pos+1,n,open+1,close);
    }
   }
}

int main() {
    int n;cin>>n;
    gen_parenthesis(0,n,0,0);


	return 0;
}
