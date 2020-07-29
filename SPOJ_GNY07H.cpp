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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,dp[N],h[N],g[N];
void solve(){
  cin>>n;
  cout<<dp[n];
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  dp[1]=1;dp[2]=5;
  h[1]=1;h[2]=6;g[1]=2;g[2]=7;
  // for recursion see http://mewtomat.blogspot.com/2016/03/spoj-gny07h-tiling-grid-with-dominoes.html
  for(int i=3;i<=1000;i++){
    dp[i]=dp[i-1]+h[i-2]+2*g[i-2]+dp[i-2];
    h[i]=h[i-2]+dp[i];
    g[i]=dp[i]+g[i-1];
  }
  int t;cin>>t;
  int x=0;
  while(t--){cout<<(++x)<<" ";solve();cout<<"\n";}
  return 0;
}