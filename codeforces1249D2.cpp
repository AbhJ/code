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
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
set<pair<int,int>>enter[N],leave[N],cnt,ans;int n,m,l,r;
void solve(){
  cin>>n>>m;
  for (int i =1; i <= n; ++i){
    cin>>l>>r;
    enter[l].insert({r,i});
    leave[r+1].insert({r,i});
  }
  for (int i = 1; i < N; ++i)
  {
    for(auto j:enter[i])cnt.insert(j);
    for(auto j:leave[i])cnt.erase(j);
    while(cnt.size()>m){
      ans.insert(*cnt.rbegin());
      cnt.erase(*cnt.rbegin());
    }
  }
  cout<<ans.size()<<"\n";
  for(auto i:ans)cout<<i.S<<" ";
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}