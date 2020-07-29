#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
long double dist(pair<ll,ll> a, pair<ll,ll> b){
    long long int ans=(a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    long double answer=sqrt(ans);return answer;
}
int main(){
    int t;ll temp1,temp2;ibs;cti;
    cin>>t;
    while(t--){
      ll x,y;cin>>x>>y;
      pair<ll,ll> ini=make_pair(x,y);
      int n,m,k;cin>>n>>m>>k;
      std::vector<pair<ll,ll>> N,M,K;
      for (int i = 0; i < n; ++i)
      {
          cin>>temp1>>temp2;N.pb(make_pair(temp1,temp2));
      }
      for (int i = 0; i < m; ++i)
      {
          cin>>temp1>>temp2;M.pb(make_pair(temp1,temp2));
      }
      for (int i = 0; i < k; ++i)
      {
          cin>>temp1>>temp2;K.pb(make_pair(temp1,temp2));
      }
      long double d=DBL_MAX,check1,check2,check;
      for (int i = 0; i < n; ++i)
      {
          check1=dist(ini,N[i]);
          if (check1>d)
            continue;
          for (int j = 0; j < m; ++j)
          {
              check2=check1+dist(N[i],M[j]);
              if (check2>d)
                continue;
              for (int z = 0; z < k; ++z)
              {
                  check=check2+dist(M[j],K[z]);
                  if (check<d)
                  {
                    d=check;
                  }
                                        
              }
          }
      }
      for (int i = 0; i < m; ++i)
      {
          check1=dist(ini,M[i]);
          if (check1>d)
            continue;
          for (int j = 0; j < n; ++j)
          {
              check2=check1+dist(N[j],M[i]);
              if (check2>d)
                continue;
              for (int z = 0; z < k; ++z)
              {
                  check=check2+dist(N[j],K[z]);
                  if (check<d)
                  {
                    d=check;
                  }
                                        
              }
          }
      }
      cout<<setprecision (std::numeric_limits<long double>::digits10 + 1)<<d<<"\n";
    }
return 0;
}