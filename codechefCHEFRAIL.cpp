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
    ibs;cti;int t;cin>>t;
    while(t--){
      int n,m;cin>>n>>m;std::vector<double> x1,x2,y1,y2;
      set<double>sy,sx;bool c1=0,c2=0;double x,y;
      for (int i = 0; i < n; ++i){cin>>x;if(x>0)x1.pb(x);if(x<0)x2.pb(x*-1);if(!x)c1=1;if(x)sx.insert(x);}
      for (int i = 0; i < m; ++i){cin>>y;if(y)sy.insert(y);else c2=1;if(y>0)y1.pb(y);if(y<0)y2.pb(y*-1);}
      ll ans=0;
      if(c1 and !c2)ans+=(n-1)*m;
      if(!c1 and c2)ans+=n*(m-1);
      if(c1 and c2)ans+=(n-1)*(m-1);
      for (int i = 0; i < x1.size(); ++i)
      {
        for(int j=0;j<x2.size();j++){
          double req=x1[i]*x2[j];
          if(sy.find(sqrt(req))!=sy.end())
            ans++;
          if(sy.find(sqrt(req)*-1)!=sy.end())
            ans++;
        }
      }
      for (int i = 0; i < y1.size(); ++i)
      {
        for(int j=0;j<y2.size();j++){
          double req=y1[i]*y2[j];
          if(sx.find(sqrt(req))!=sx.end())
            ans++;
          if(sx.find(sqrt(req)*-1)!=sx.end())
            ans++;
        }
      }
      cout<<ans<<"\n";
    }
    // cout<<day_of_week(2020,3,1);
    return 0;
}