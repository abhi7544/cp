#include <bits/stdc++.h>
#include<vector>
 using namespace std;
 int main()
  {

  vector <int> v;
  int n;
  cin>>n;
 for(int i=1;i<=n;i++)
   v.push_back(i);



  cout<<"size: "<<v.size()<<" capacity: "<<v.capacity()<<endl;
  v.push_back(2);
   cout<<"size: "<<v.size()<<" capacity: "<<v.capacity()<<endl;
   v.push_back(4);
   cout<<"size: "<<v.size()<<" capacity: "<<v.capacity()<<endl;
    v.push_back(6);
     cout<<"size: "<<v.size()<<" capacity: "<<v.capacity()<<endl;
     v.push_back(3);
     cout<<"size: "<<v.size()<<" capacity: "<<v.capacity()<<endl;
     v.push_back(3);
     cout<<"size: "<<v.size()<<" capacity: "<<v.capacity()<<endl;
     v.push_back(6);
     cout<<"size: "<<v.size()<<" capacity: "<<v.capacity()<<endl;
     v.push_back(5);
     cout<<"size: "<<v.size()<<" capacity: "<<v.capacity()<<endl;
vector<int>::iterator i;

for(i=v.begin();i<v.end();i++)
 cout<<*i;
    }