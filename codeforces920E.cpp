#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll n;
set<int>a[N],s;
ll dfs(int x){
  ll num=1;
  for(auto i=s.begin();i!=s.end();){
    if(a[x].count(*i)==0)s.erase(i),num+=dfs(*i),i=s.lower_bound(*i);
    else i++;
  }
  return num;
}
void solve(){
  ll m;cin>>n>>m;
  for (ll i = 0; i < m; ++i)
  {
    int x,y;cin>>x>>y;
    a[x].insert(y),a[y].insert(x);
  }
  vector<ll> v;
  for (int i = 1; i <= n; ++i)s.insert(i);
  for (int i = 1; i <= n; ++i)
  {
    if(s.count(i)){
      v.pb(dfs(i));
    }
  }
  cout<<v.size()<<"\n";
  sort(v.begin(), v.end());
  for(auto i:v)cout<<--i<<" ";
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}