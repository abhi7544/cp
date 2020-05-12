#include<bits/stdc++.h>
#define MAX 65535
#define toint(c) (int(c)-48)
using namespace std;
char code[27]={'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<string> res;
vector<string>way_code(string s,int pos,int trav)
{
 static char str[MAX];

    if(trav==s.size())
    {
      int i;
    string s = "";
    for (i = 0; i < pos; i++) {
        s = s + str[i];
    }
      res.push_back(s);


    }
    else
    {
     str[pos]=code[toint(s[trav])];

     way_code(s,pos+1,trav+1);

     if(trav<s.size()-1)
     {
      int v=toint(s[trav])*10+toint(s[trav+1]);
        if(v>=1&&v<=26)
        {
         str[pos]=code[v];
         way_code(s,pos+1,trav+2);
        }
     }

    }
return res;
}
int main() {

    string s;
    cin>>s;
 vector<string>ans=way_code(s,0,0);
 int i;
 cout<<"[";
 for( i=0;i<ans.size()-1;i++)
 {
     cout<<ans[i]<<",";
 }
	cout<<ans[i]<<"]";
	return 0;
}
