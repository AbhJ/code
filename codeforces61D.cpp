#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
vector<vector<pair<int,int>>>a;
// int i,a[10],ans;
// ll dist[N]={(ll)1e18};
bool u[N];
ll len;
void dfs(int x,ll w=0,int y=-1){
    ll ma=0;
    for(auto Y:a[x]){
      if(y!=Y.F)
        dfs(Y.F,w+Y.S,x);
    }
    len=max(w,len);
}
void solve(){
  int n;cin>>n;
  a=vector<vector<pair<int,int>>>(n+10);
  ll ans=0;
  for (int i = 0; i < n-1; ++i)
  {
    int u,v,w;cin>>u>>v>>w;ans+=w;
    a[u].pb({v,w}),a[v].pb({u,w});
  }
  ans=ans<<1;
  dfs(1);
  // cout<<len;
  cout<<ans-len;
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