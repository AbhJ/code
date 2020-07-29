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
const int N=5e3+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,n1,n2,n3,x,y,num=0,vis[N],col[N],cnt[2][N],dp[N][N];vector<int>a[N],c[2][N];
void dfs(int u){
  vis[u]=1;cnt[col[u]][num]++;
  c[col[u]][num].pb(u);
  for(auto i:a[u]){
    if(col[i]==-1)col[i]=1^col[u],dfs(i);
    if(col[i]==col[u]){cout<<"NO";exit(0);}
  }
}
void solve(){
  cin>>n>>m>>n1>>n2>>n3;
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
  }
  for(int i=1;i<=n;i++)col[i]=-1;
  for(int i=1;i<=n;i++){
    if(vis[i]==0){
      col[i]=0;
      num++;
      dfs(i);
    }
  }
  memset(dp,-1,sizeof dp);dp[0][0]=0;
  for(int i=1;i<=num;i++){
    for(int j=0;j<=n;j++){
      for(int k=0;k<2;k++)
      if(j-cnt[k][i]>=0 and dp[i-1][j-cnt[k][i]]!=-1)/*cout<<i<<j<<" ",*/dp[i][j]=k;
    }
  }
  //dp[i][z] is color of ith conn comp if it has z components as n2
  if(dp[num][n2]==-1){cout<<"NO";exit(0);}
  cout<<"YES\n";
  for(int i=num;i;i--){
    int colo=dp[i][n2];
    for(auto i:c[colo][i])col[i]=2;
    n2-=cnt[colo][i];
    if(n2<0)break;
  }
  for(int i=1;i<=n;i++)if(col[i]!=2){
    if(n1>0)n1--,col[i]=1;
    else n3--,col[i]=3;
  }
  for(int i=1;i<=n;i++)cout<<col[i];
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