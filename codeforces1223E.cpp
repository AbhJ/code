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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,k,x,y,w;vvpii a;vvi dp;
void dfs(int u,int p=-1){
  int ans=0;
  vi v;
  for(auto i:a[u]){
    if(i.F!=p){
      dfs(i.F,u);
      // ans=max(ans,i.S+dfs(i,u,1));
      // ans=max(ans,dfs(i,u,0));
    }
  }
  for(auto i:a[u]){
    if(i.F!=p){
      ans+=dp[i.F][1];
      v.pb(dp[i.F][0]+i.S-dp[i.F][1]);
    }
  }
  sort(all(v));
  reverse(all(v));
  rep(i,0,min(k-2,(int)v.size()-1))ans+=max(0LL,v[i]);
  dp[u][0]=dp[u][1]=ans;
  if((int)v.size()-1>=k-1)dp[u][1]+=max(0LL,v[k-1]);
}
void solve(){
  cin>>n>>k;a=vvpii(n+1);
  dp=vvi(n+1,vi(2,0));
  rep(i,1,n-1){
    cin>>x>>y>>w;
    a[x].pb({y,w}),
    a[y].pb({x,w});
  }
  dfs(1);
  cout<<dp[1][1];
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}