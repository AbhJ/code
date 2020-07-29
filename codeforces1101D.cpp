//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <unordered_map> 
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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,x,y,A[N],ans;vector<int>a[N];map<int,int>dp[N];
void dfs(int u,int p=-1){
  for(auto i:a[u])if(i!=p){
    dfs(i,u);
    for(auto g1:dp[u])
      for(auto g2:dp[i]){
        if(__gcd(g1.F,g2.F)!=1 and __gcd(A[i],A[u])!=1)ans=max(ans,g1.S+g2.S);
      }
    for(auto g1:dp[i]){
      if(__gcd(g1.F,A[u])!=1)dp[u][__gcd(g1.F,A[u])]=max(dp[u][__gcd(g1.F,A[u])],g1.S+1);
    }
  }
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){cin>>A[i];
  if(A[i]!=1)dp[i][A[i]]=1;}
  for(int i=1;i<=n-1;i++){
    cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
  }
  dfs(1);
  // int ma=0;
  for(auto i:dp[1])ans=max(i.S,ans);
  // if(ma==1 and F==0)cout<<0;else
  // cout<<ma;
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
}