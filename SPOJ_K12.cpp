//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
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
#define res(vector) v.resize(unique(v.begin(), v.end()) - v.begin());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,p[N],ans;vector<pair<int,int>>a;
int cost(int h,int l=1,int r=n){
  int c=0;
  for(int i=l;i<=r;i++)c+=abs((a[i].F-h)*(a[i].S));
  return c;
}
void solve(){
  cin>>n;ans=inf;a=vector<pair<int,int>>(n+1,{0,0});
  for(int i=1;i<=n;i++)cin>>a[i].F;
  for(int i=1;i<=n;i++)cin>>a[i].S;
  sort(a.begin()+1,a.begin()+1+n);int l=0,r=1e4;
  while(l<r){
    int m=l+r>>1;
    if(cost(m)<cost(m+1))r=m;
    else l=m+1;
  }
  ans=min(ans,min(cost(l),cost(l+1)));
  cout<<ans;
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