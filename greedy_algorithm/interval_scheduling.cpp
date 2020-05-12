#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}
int count_max_activity(vector<pair<int ,int>> activity)
{
int count=0;
pair<int,int> pre(make_pair(-1,-1));
for(auto x:activity)
{
    if(x.first>=pre.second)
    {
        count++;
          pre=x;
    }

}
return count;
}

int main() {
    int T,N;
    int m,n;
    vector<pair<int,int>> activity;
    cin>>T;
    while(T--)
    {
        cin>>N;
        activity.clear();
        while(N--)
        {
            cin>>m>>n;
            pair<int,int> interval(make_pair(m,n));
            activity.push_back(interval);
        }

        sort(activity.begin(),activity.end(),compare);

      cout<<count_max_activity(activity)<<endl;
    }
}
