//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define res(vector) v.resize(unique(v.begin(), v.end()) - v.begin());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,a,b,x,y,c,i,cost,p[N];vector<int>A[N],vis[3],d[3];
void bfs(int s,int k){
  queue<int> q;
  q.push(s);
  vis[k][s]=1;
  while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : A[v]) {
          if (vis[k][u]==0) {
              vis[k][u]=1;
              q.push(u);
              d[k][u] = d[k][v] + 1;
          }
      }
  }
}
void solve(){
  cin>>n>>m>>a>>b>>c;cost=inf;for(;i<3;i++)vis[i]=vector<int>(n+1,0),d[i]=vector<int>(n+1,0);
  for(int i=1;i<=n;i++)A[i].clear();
  for(int i=1;i<=m;i++)cin>>p[i];
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    A[x].pb(y),A[y].pb(x);
  }
  sort(p+1,p+1+m);
  for(int i=1;i<=m;i++)p[i]+=p[i-1];
  bfs(a,0);bfs(b,1);bfs(c,2);
  for(int i=1;i<=n;i++){
    if(d[0][i]+d[1][i]+d[2][i]<=m)
      cost=min(cost,p[d[0][i]+d[1][i]+d[2][i]]+p[d[1][i]]);
  }
  cout<<cost;
}
int32_t main()
{
  // ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;i=0,solve();cout<<"\n";}
  return 0;
}