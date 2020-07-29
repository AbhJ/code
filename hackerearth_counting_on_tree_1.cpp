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
const int N=5e4+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,k,A[N],dp[N][105],subtree[N],f[N];vvi a;
int mul(int a,int b){
  return ((a%M)*(b%M))%M;
}
int add(int a,int b){
  return ((a%M)+(b%M))%M;
}
void dfs(int u,int y=-1){
  dp[u][A[u]]=1;
  subtree[u]=1;
    for(auto v: a[u])if(v!=y){
      dfs(v,u);
      vector<int> temp(k+1,0);
      for(int i=0;i<=min(subtree[u],k);i++){
          for(int j=0;j<=min(subtree[v],k-i);j++){
              temp[i+j] = add(temp[i+j],mul(dp[u][i],dp[v][j])); 
          }
      }
      for(int i=0;i<=min(k,subtree[u]+subtree[v]);i++) dp[u][i] = add(temp[i],dp[u][i]);
      subtree[u] += subtree[v];
    }
}
void solve(){
  cin>>n>>k;a=vvi(n+1);a.clear();memset(A,0,sizeof A);
  memset(dp,0,sizeof dp);memset(subtree,0,sizeof subtree);
  rep(i,1,n)cin>>A[i];
  rep(i,1,n-1){
    int x,y;cin>>x>>y;
    a[x].pb(y);a[y].pb(x);
  }
  dfs(1);
  int ans=0;
  rep(i,1,n)ans=add(ans,dp[i][k]);
  cout<<ans;
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