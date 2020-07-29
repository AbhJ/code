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
set<int>a[N];
set<int>s;
int n,m;
void dfs(int u){
  // if(!s.count(u))return;
  s.erase(u);
  vector<int>q;
  for(auto i:s)if(!a[u].count(i))q.pb(i);
  for(auto i:q)s.erase(i);
  for(auto i:q)dfs(i);
}
void solve(){
  cin>>n>>m;
  for (int i = 0; i < m; ++i)
  {
    int x,y;cin>>x>>y;
    a[x].insert(y),a[y].insert(x);
  }
  for (int i = 0; i < n; ++i)
  {
    s.insert(i+1);
  }
  int ans=0;
  for(int i=0;i<n;i++)
    if(s.count(i+1)){
      dfs(i+1);
      ans++;
    }
  cout<<ans-1;
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