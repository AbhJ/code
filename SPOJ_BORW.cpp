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
const int N=2e2+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,a[N],dp[N][N][N];
//dp[pos][x][y] is ans for length pos where largest increasing sub ends at x
//and largest decreasing sub ends at y
int f(int pos=1,int x=-1,int y=-1){
  if(pos>n or pos<1)return 0;
  if(dp[pos][x][y])return dp[pos][x][y];
  int ans=f(pos+1,x,y);//not taking this element
  if(x==-1 or a[pos]>a[x])ans=max(ans,1+f(pos+1,pos,y));
  if(y==-1 or a[pos]<a[y])ans=max(ans,1+f(pos+1,x,pos));
  return dp[pos][x][y]=ans;
}
void solve(){
  cin>>n;
  if(n==-1)exit(0);
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=n;i++)cin>>a[i];
  cout<<n-f();
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  while(1){solve();cout<<"\n";}
  return 0;
}