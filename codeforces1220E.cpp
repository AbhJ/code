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
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,x,y,s,A[N],vis[N],dp[N],cycler_sum;set<pii>used_roads;vi a[N];
int dfs(int u,int p=-1){
  vis[u]=1;
  dp[u]=A[u];
  int hit_cycle=0;
  //for every city we store the maximum cost to reach city
  for(auto i:a[u]){
    if(vis[i]==1 and i!=p){hit_cycle=1;}
    if(vis[i]==0){
      vis[i]=1;
      if(dfs(i,u)==1)hit_cycle=1;
      dp[u]=max(dp[u],dp[i]+A[u]);
    }
  }
  if(hit_cycle==1)cycler_sum+=A[u];
  else x=max(x,dp[u]);
  return hit_cycle;
}
void solve(){
  cin>>n>>m;
  rep(i,1,n)cin>>A[i];
  rep(i,1,m)cin>>x>>y,a[x].pb(y),a[y].pb(x);
  cin>>s;x=0;
  dfs(s);
  cout<<cycler_sum+x;
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}