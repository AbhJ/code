#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
std::vector<pair<int,int>> S[200009];//index are duration
int main()
{
    ibs;cti;
    int n,x;scanf ("%d %d",&n,&x);
    for (int i = 0; i < n; ++i)
    {
        int l,r,cost;scanf ("%d %d %d",&l,&r,&cost);
        S[r-l+1].pb({l,cost});
    }
    for (int i = 1; i <= x; ++i)
        sort(S[i].begin(), S[i].end());
    int cost=INT_MAX;
    for (int i1 = 1; i1 < x; ++i1)
    {
        int c=INT_MAX;
        std::vector<pair<int,int>> v=S[i1],u=S[x-i1];
        if(u.empty() or v.empty())continue;
        for (int i = 0,j=0; i < u.size(); ++i)
        {
            for (; j < v.size(); ++j)
            {
                if(v[j].first+i1-1>=u[i].first) break;
                c=min(c,v[j].second);
            }
            if(c!=INT_MAX)cost=min(cost,c+u[i].second);
        }
    }
    if(cost!=INT_MAX)
        cout<<cost<<"\n";
    else cout<<-1<<"\n";
    return 0;
}