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
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int ans,ma,a[N],l[N],r[N],n,m,dp[N],j,L=-1;set<int>s;
void solve(){
  cin>>n;L=-1;
  s.clear();ma=1;ans=0;j=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(s.count(a[i])==0)l[a[i]]=0;
    if(l[a[i]]==0)l[a[i]]=i;
    r[a[i]]=i;
    s.insert(a[i]);
  }
  if(is_sorted(a+1,a+1+n)==1){cout<<"0";return;}
  for(auto i:s){
    if(L!=-1){
      if(r[L]<l[i])dp[i]=1+dp[L];
      else dp[i]=1;
      ma=max(ma,dp[i]);
    }
    else dp[i]=1;
    L=i;
  }
  cout<<s.size()-ma;
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}