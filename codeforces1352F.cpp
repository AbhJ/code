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
const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
//dp[i][j] is longest increasing subsequence from i to j
int z,o,t;
void solve(){
  //constructive approach first settle z then t then o
  cin>>z>>o>>t;
  if(z!=0 or o!=0) for(int i=1;i<=z+1;i++)cout<<0;//z done
  if(o!=0 or t!=0) for(int i=1;i<=t+1;i++)cout<<1;//o done
  //while printing 1 we already encountered one 01 pair iff o!=0 or t!=0
  for (int i = 1; i <= o-1; ++i)
  {
    if(i&1)cout<<0;else cout<<1;
  }
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}