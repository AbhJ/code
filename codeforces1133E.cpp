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
const int N=5e3+4;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],dp[N][N];
int n,k,l,r;
void solve(){
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+1+n);
  l=1;
  for(r=1;r<=n;r++){
    while(a[r]-a[l]>5)l++;
    //our group consists from a[l] to a[r]
    //last possible r was l-1
    for(int i=1;i<=k;i++)
      dp[i][r]=max(dp[i][r-1],dp[i-1][l-1]+(r-l+1));
  }
  cout<<dp[k][n];
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}