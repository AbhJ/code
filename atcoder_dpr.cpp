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
const int N=5e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int mul(int a,int b){
  return ((a%M)*(b%M))%M;
}
int add(int a,int b){
  return ((a%M)+(b%M))%M;
}
int n;
vvi p(vvi a,vvi b){
  vvi x(n,vi(n,0));
  rep(i,0,n-1)
    rep(j,0,n-1)
      rep(k,0,n-1)
        x[i][j]=add(x[i][j],mul(a[i][k],b[k][j]));
  return x;
}
vvi a;
//this return pow(A,x) where A is matrix
vvi matrix_power_final(vvi A, int x){
  vvi result(n,vi(n,0));
  rep(i,0,n-1)result[i][i]=1;
  while(x){
    if (x&1)result = p(result , A);
    A = p(A , A);
    x = x / 2;
  }
  return result;
}
void solve(){
  int k;cin>>n>>k;a=vvi(n,vi(n,0));
  rep(i,0,n-1)rep(j,0,n-1)cin>>a[i][j];
  a=matrix_power_final(a,k);
  int ans=0;
  rep(i,0,n-1)rep(j,0,n-1)ans=add(ans,a[i][j]);
  cout<<ans;
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