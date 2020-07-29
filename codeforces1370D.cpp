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
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int a[N],n,k;
bool f(int x){
  //check for odd first
  int cnt=0,now=1;
  rep(i,1,n){
    if(now==1){
      if(a[i]<=x)cnt++,now=0;
    }
    else if(now==0){
      cnt++,now=1;
    }
  }
  if(cnt>=k)return 1;
  now=cnt=0;
  //check for even first
  rep(i,1,n){
    if(now==1){
      if(a[i]<=x)cnt++,now=0;
    }
    else if(now==0){
      cnt++,now=1;
    }
  }
  if(cnt>=k)return 1;
  return 0;
}
void solve(){
  cin>>n>>k;
  rep(i,1,n)cin>>a[i];
  int l=1,r=inf,ans=inf;
  while(l<r){
    int m=l+r>>1;
    if(f(m))r=m;
    else l=m+1;
  }
  cout<<l;
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}