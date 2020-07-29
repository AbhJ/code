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
vector<int>a[N];
int ma;//tracks max node covered till now
bool vis[N];
void dfs(int u){
  vis[u]=1;ma=max(u,ma);
  for (auto i:a[u])if(!vis[i])
  {
    dfs(i);
  }
}
void solve(){
  int n,m;cin>>n>>m;
  for (int i = 0; i < m; ++i)
  {
    int x;int y;cin>>x>>y;
    a[x].pb(y);a[y].pb(x);
  }
  ll ans=0;
  for (int i = 1; i <= n; ++i)
  {
    if(!vis[i]){
      if(i<ma)//this vertex aint been covered in any connected component
        ans++;
      dfs(i);
    }
  }
  cout<<ans;
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