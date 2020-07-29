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
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
ll mul(ll a,ll b){
  return ((a%M)*(b%M))%M;
}
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int n,t,x,y,O,Z,o[N],z[N];string s;
void solve(){
  cin>>x>>y;O=o[y]-o[x-1];
  Z=z[y]-z[x-1];
  cout<<mul(powM(2,O)-1,powM(2,Z));
}
int main()
{
  ibs;cti;
  cin>>n>>t>>s;s='#'+s;
  for (int i = 1; i <= n; ++i)
  {
    o[i]=o[i-1]+(s[i]=='1');
    z[i]=z[i-1]+(s[i]!='1');
  }
  // solve(),cout<<"\n";
  // int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}