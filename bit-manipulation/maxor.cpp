
#include <iostream>
using namespace std;
int main()
{
    int a=5,s=31,i,max;
for(;i>0;)
{
    i=1<<s;
    cout<<"i="<<i<<endl;
     if(i&a)
     {goto lb;}
s--;

}
lb:
cout<<s;


    return 0;
}
