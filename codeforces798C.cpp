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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],ans;
int n;
void solve(){
  cin>>n;
  cout<<"YES\n";
  for(int i=1;i<=n;i++)cin>>a[i];int g=a[1];
  for(int i=1;i<=n;i++){
    g=__gcd(g,a[i+1]);
    if(a[i]&1){
      if(a[i+1]&1)ans++;
      else ans+=2;
      a[i+1]=2;
    }
  }
  if(g!=1)cout<<0;else
  cout<<ans;
}
int32_t main()
{
  // ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}