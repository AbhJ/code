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
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int dp[N];
ll add(ll a,ll b){
  return ((a%M)+(b%M))%M;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
void solve(){
  int n,k;cin>>n>>k;
  vi a(n);
  rep(i,0,n-1)cin>>a[i];
  //dp[i][j] is the ans for i children considered and j candies distributed
  // (i>=x)dp[i][j]=x+dp[i-x][j-1];
  dp[0]=1;
  vi p(k+1,0);
  rep(i,0,n-1){
    p=vi(k+1,0);
    per(j,k,0){
      int l=j+1;
      int r=min(j+a[i],k);
      if(l<=r){
        p[l]=add(p[l],dp[j]);
        if(r<k)p[r+1]=sub(p[r+1],dp[j]);
      }
    }
    int pref=0;
    rep(j,0,k){
      pref=add(pref,p[j]);
      dp[j]=add(dp[j],pref);
    }
  }
  cout<<dp[k];
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