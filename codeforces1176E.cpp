#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
// ll dfs(int x,int i,int pls=1,bool st=0){
//     u[x]=1;
//     if(st)c[x]=i+1;
//     for(int y:e[x])if(!u[y])
//         return v[i][x]+dfs(y,(i+pls)%3,pls,st);
//     return v[i][x];
// }
int d[N];
vector<vector<int>> a;
void bfs(int s) {
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();q.pop();
    for (auto to : a[v]) {
      if (d[to] == -1) {
        d[to] = d[v] + 1;
        q.push(to);
      }
    }
  }
}
void solve(){
  int n,m;cin>>n>>m;
  // for(int i=0;i<N;i++)a[i].clear();
  a=std::vector<std::vector<int> > (n);
  for (int i = 0; i < m; ++i)
  {
    int x,y;cin>>x>>y;x--,y--;
    a[x].pb(y),a[y].pb(x); 
  }
  memset(d,-1,sizeof(int)*(n));
  bfs(0);
  std::vector<int> v[2];
  for (int i = 0; i < n; ++i)
  {
    if(d[i]==-1)continue;
    if(d[i]%2)v[0].pb(i+1);else v[1].pb(i+1);
    // cout<<i<<" "<<d[i]<<"\n";
  }
  if(v[0].size()>v[1].size())v[0]=v[1];
  cout<<v[0].size()<<"\n";
  for (int i = 0; i < v[0].size(); ++i)
    cout<<v[0][i]<<" ";
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}