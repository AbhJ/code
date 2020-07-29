#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
int main()
{   
    ibs;cti;
    int n,m;cin>>n>>m;std::vector<pair<string,string>> v(n);
    int x=INT_MIN;
    for (int i = 0; i < n; ++i){
      cin>>v[i].first;v[i].second=v[i].first;
      reverse(v[i].second.begin(), v[i].second.end());
      if(v[i].first==v[i].second)x=i;
    }
    std::vector<int> c;set<int> s;
    for (int i = 0; i < n; ++i)
    {
      for (int j = i+1; j < n; ++j)
      {
        if(v[i].first==v[j].second)
          c.pb(i),s.insert(i);
      }
    }
    string ans;
    for (int i = 0; i < n; ++i)
    {
      if(v[i].first==v[i].second and s.find(i)==s.end())
        ans=v[i].first;
    }
    for (int i = 0; i < c.size(); ++i)
    {
      ans=v[c[i]].first+ans;
      ans+=v[c[i]].second;
    }
    cout<<ans.length();
    cout<<"\n"<<ans<<"\n";
    return 0;
}