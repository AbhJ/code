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
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int dp[N],l[N],x,y;//p[i] is index of biggest paintrd sequence that painted it
void solve(){
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)l[i]=l[i-1]+1;
  for (int i = 0; i < q; ++i)
  {
    cin>>x>>y;
    for(int j=x;j<=y;j++)l[j]=min(l[j],x);
  }
  for (int j = 0; j < q-2; ++j)
  {
    for(int i=n;i>0;i--)dp[i]=max(dp[i],dp[l[i]-1]+i-l[i]+1);
    for(int i=1;i<=n;i++)dp[i]=max(dp[i],dp[i-1]);
  }
  // for(int i=n;i>1;i--)x=max(x,dp[i]);
  cout<<dp[n];
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}