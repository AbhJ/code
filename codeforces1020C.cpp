#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const ll M =  998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  std::vector<int> v[3030];
  int ma=0;ll c=1e18;
  int n,m;cin>>n>>m;
  for (int i = 0; i < n; ++i)
  {
    int x,y;cin>>x>>y;v[x].pb(y);
  }
  for (int i = 1; i <= m; ++i)
  {
    sort(v[i].begin(), v[i].end()),ma=max(ma,(int)v[i].size());
  }
  for (int i = 1; i <= ma+1; ++i)
  {
    ll s=0;std::vector<int> a;
    int s1=v[1].size();
    for (int j=2;j<=m;j++)
        for (int k=0;k<v[j].size();k++)
            if (v[j].size()-k>=i)s+=v[j][k],s1++;
            else
                a.push_back(v[j][k]);
    sort(a.begin(),a.end());
    if (a.size()+s1<i)continue;
    for (int j=0;j+s1+1<=i and j<a.size();j++)
        s+=a[j];
    c=min(c,s);
  }
  cout<<c<<"\n";
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}