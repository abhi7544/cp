using namespace std;
#include<bits/stdc++.h>

struct process
{
public :
int pno,at,bt,wt,ct,tat,rt;

};
int main()
{
int n,q;
float taT=0,wT=0;
process p[20];
cout<<"Enter no of Process:";cin>>n;
cout<<"Enter Quantum:";cin>>q;
cout<<"Pn AT BT  \n";
for(int i=0;i<n;i++)
{
cout<<(p[i].pno=(i+1));cin>>p[i].at>>p[i].bt;
p[i].rt=p[i].bt;
}
int remain=n,flag,i;
cout<<"Process\tTat\tWt\n";
 for(int time=0,i=0;remain!=0;) 
  { 
    if(p[i].rt<=q && p[i].rt>0) 
    { 
      time+=p[i].rt; 
      p[i].rt=0; 
      flag=1; 
    } 
    else if(p[i].rt>0) 
    { 
      p[i].rt-=q; 
      time+=q; 
    } 

if(p[i].rt==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-p[i].at,time-p[i].at-p[i].bt); 
      wT+=time-p[i].at-p[i].bt; 
      taT+=time-p[i].at ;
      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(p[i+1].at<=time) 
      i++; 
    else 
      i=0; 
  } 


cout<<"Average Waiting time="<<wT/n<<"\n"<<"Average TAT time ="<<taT/n;
return 0; 
}