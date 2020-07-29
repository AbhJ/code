#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
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
const int N=1e5+4;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
const double pi=acos(-1);
int n;double x,s,ans;
void solve(){
  cin>>n;ans=s=0;
  if(n&1){cout<<setprecision(20)<<1.0/(2.0*sin(pi/(4*n)));return;}
  x=pi/n;
  for(int i=1;i<=n;i++)ans+=abs(cos(s)),s+=x;
  cout<<setprecision(20)<<ans;
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int x=0;
  int t;cin>>t;while(t--){solve();cout<<"\n";}
  return 0;
}