#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
// std::vector<pair<int,int>> S[200009];//index are duration
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      int n;cin>>n;std::vector<int> q(n+1),p;std::vector<int> v;q[0]=0;
      for (int i = 1; i <= n; ++i)
      {
        cin>>q[i];bool c=1;
        if(v.size() and q[i]==q[i-1]){
            p.pb(v.back());
            v.pop_back();c=0;
        }
        if(i==q[i] and c)p.pb(i);
        else{
          for (int j = q[i-1]+1; j < q[i]; ++j)
          {
            v.pb(j);/*if(c)cout<<j;*/
          }
          if(q[i]!=q[i-1] and c)
            p.pb(q[i]);
        }
        // else p[i]=q[i];
      }
      if(p.size()==n){
        for (int i = 0; i < n; ++i)
        {
          cout<<p[i]<<" ";
        }
      }
      else cout<<"-1 ";
      cout<<"\n";
    }
    return 0;
}