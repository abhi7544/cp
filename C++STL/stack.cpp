#include<bits/stdc++.h>
using namespace std;

 int main()
  {
   int t;
   stack <int> s;
   cout<<"1. print the top most element\n2 x push x into the stack\n3.pop the top most element\n 4.print size of the stack\n";
   cout<<"Enter number of queries: ";
   cin>>t;
cout<<"input:\n";
vector<int> q;
vector<int>x;
for(int i=0;i<t;i++)
{
 scanf("%[^ ]%d",&q[i]);
 if(q[i]==2)
 {
  cin>>x[i];
 }

}




int i=0;

   do
   {

    switch(q[i])
    {
    case 1:cout<<s.top()<<endl;break;
    case 2: s.push(x[i]);break;
    case 3:s.pop();break;
    case 4:cout<<s.size()<<endl;
    break;


    }
i++;
   }while(i<t);

return 0;
  }