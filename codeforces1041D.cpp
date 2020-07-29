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
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,h;
void solve(){
  cin>>n>>h;vector<pair<int,int>>v(n);
  for(int i=0;i<n;i++)cin>>v[i].F>>v[i].S;
  int sum=0,ans=0,j=0;
  for (int i = 0; i < n; ++i)
  {
    if(i)sum-=v[i-1].S-v[i-1].F;
    while(j<n and sum+h>v[j].F-v[i].F)
      sum+=v[j].S-v[j].F,j++;
    ans=max(ans,sum+h);
  }
  cout<<ans;
}
int32_t main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}