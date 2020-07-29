#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
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
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e1+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int open[N],m,cost[N][N],rat[N][N],dp[N][2][50*N];
int f(int n,bool o,int k){
  if(dp[n][o][k]!=0)return dp[n][o][k];
  if(open[n]==-1)return 0;
  int ans=f(n+1,0,k);//don't take this box
  if(o==0)//nth box is not open
  if(open[n]<=k){
    k-=open[n];
    //let's open this box
    for(int num=1;num<=m;num++){
      if(k>=cost[n][num])
        ans=max(ans,rat[n][num]+f(n,1,k-cost[n][num]));
    }
    k+=open[n];
  }
  if(o==1)
  for(int num=1;num<=m;num++){
      if(k>=cost[n][num])
        ans=max(ans,rat[n][num]+f(n,1,k-cost[n][num]));
    }
  return dp[n][o][k]=ans;
}
int n,k;
void solve(){
  cin>>n>>m>>k;memset(dp,0,sizeof(dp));
  for(int i=1;i<=n;i++)cin>>open[i];
  open[n+1]=-1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>cost[i][j];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>rat[i][j];
  cout<<f(1,0,k);
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  // int x=0;
  while(t--){solve();cout<<"\n";}
  return 0;
}