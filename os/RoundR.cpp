using namespace std;
#include<bits/stdc++.h>

class process
{
public :int pno,pr,at,bt,st,wt,tat;

};

int main()
{
int n;
cout<<"Enter no of Process:";cin>>n;
process p[20];
cout<<"Arrival Time Burst Time   Priority\n";
for(int i=0;i<n;i++)
{
cin>>p[i].at>>p[i].bt>>p[i].pr;

}
return 0;	
}