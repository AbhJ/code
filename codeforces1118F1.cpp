#include <bits/stdc++.h>
#include <numeric>
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
#define F first
#define S second
int U[N];vector<vector<int>> a;int ans,R,B;
pair<int,int> dfs(int v, int p=-1){
    int r=0,b=0;
    if(U[v]==1)r++;if(U[v]==2) b++;
    for(int y:a[v])if(y!=p){
      auto t=dfs(y,v);//scans through all possible paths
      if((t.F==R) and (t.S==0))ans++;
      if((t.F==0) and (t.S==B))ans++;
      r+=t.F;b+=t.S;
    }
    return {r,b};
}
void solve(){
  int n;cin>>n;int x;
  a=vector<vector<int>>(n+10);
  for (int i = 0; i < n; ++i){
    cin>>x;if(x==1)R++;if(x==2) B++;U[i]=x;
  }
  for (int i = 0; i < n-1; ++i){
    int u,v;cin>>u>>v;u--,v--;a[u].pb(v);a[v].pb(u);
  }
  dfs(0);cout<<ans;
}
int main()
{
    ibs;cti;
    solve();
    cout<<"\n";
    return 0;
}