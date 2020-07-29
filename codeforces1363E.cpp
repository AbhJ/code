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
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,a[N],b[N],c[N],dp[N][2],ans,x,y;vector<int>A[N];
void dfs(int u,int p=1){
  a[u]=min(a[u],a[p]);
  for(auto i:A[u])if(i!=p){
    dfs(i,u);
    dp[u][1]+=dp[i][1];
    dp[u][0]+=dp[i][0];
  }
  if(c[u]!=b[u])dp[u][b[u]]++;
  int mi=min(dp[u][1],dp[u][0]);
  dp[u][1]-=mi,dp[u][0]-=mi;
  ans+=2*mi*a[u];
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
  for(int i=1;i<=n-1;i++){
    cin>>x>>y;
    A[x].pb(y),A[y].pb(x);
  }
  dfs(1);
  if(dp[1][1]!=dp[1][0]){cout<<-1;return;}
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