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
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
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
int n,m,x,k,y,a[N],b[N];
void solve(){
  cin>>n>>m>>x>>k>>y;
  rep(i,1,n)cin>>a[i];
  rep(i,1,m)cin>>b[i];
  vi v={0};
  int j=1;
  rep(i,1,n){
    if(a[i]==b[j])j++,v.pb(i);
  }
  v.pb(n+1);
  if(j!=m+1)cout<<-1,exit(0);
  int cos=0;
  rep(i,0,v.size()-2){
    int st=v[i]+1,en=v[i+1]-1;
    if(st>en)continue;
    // cout<<st<<" "<<en<<"\n";
    int ma=*max_element(a+st,a+en+1);
    int len=en-st+1;
    if(k*y<x){
      if(a[st-1]>ma or a[en+1]>ma)cos+=len*y;
      else cos+=x+(len-k)*y;
    }
    else cos+=(len/k)*x+(len%k)*y;
    if(a[st-1]<ma and a[en+1]<ma and len<k){cout<<-1,exit(0);}
  }
  cout<<cos;
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