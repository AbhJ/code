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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,c[N],x,y,dp[2][N],ans[N],P[N];vector<int >a[N];
void dfs(int u,int p=0){
  int x=0;P[u]=p;ans[u]=c[u];
  for(auto i:a[u])if(i!=p){
    dfs(i,u);
    // x=max(x,dp[1][i]-dp[0][i]);
    // dp[0][u]+=dp[0][i];
    // dp[1][u]+=dp[1][i];
    ans[u]+=max(0LL,ans[i]);
  }
  // dp[c[u]][u]++;
  if(c[u]==0)ans[u]--;
  // cout<<u<<" "<<dp[1][u]-dp[0][u]<<"\n";
  // ans[u]=max(dp[1][u]-dp[0][u],x);
  // for(auto i:a[u])if(i!=p){
  //   ans[i]=max(ans[i],ans[u]);
  // }
}
void d(int u,int p=0){
 if(p!=0){ if(ans[u]<0)
   ans[u]=max(ans[u],ans[p]-1);
   else ans[u]=max(ans[u],ans[p]);}
  for(auto i:a[u])if(i!=p){
    d(i,u);
    // ans[u]=max(ans[u],dp[1][i]-dp[0][i]);
  }
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>c[i];
  for(int i=1;i<=n-1;i++){
    cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
  }
  dfs(1);
  d(1);
  // for(int i=1;i<=n;i++)ans[i]=max(ans[i],ans[P[i]]);
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
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