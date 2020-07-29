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
// #define double int
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
const int inf = /*0x3f3f3f3f*/3e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 4294967296 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,k,x,y,w,c=inf;
int mul(int a,int b){
  // return ((a%M)*(b%M))%M;
  return a*b;
}
int add(int a,int b){
  // return ((a%M)+(b%M))%M;
  a+=b;
  // if(a>=M)a-=M;
  return a;
}
vvi p(vvi a,vvi b){
  vvi x(n,vi(n,inf));
  rep(i,0,n-1)
    rep(j,0,n-1)
      rep(k,0,n-1)
        x[i][j]=min(x[i][j],add(a[i][k],b[k][j]));
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
  cin>>n>>m>>k;
  a=vvi(n,vi(n,inf));
  rep(i,1,m){
    cin>>x>>y;cin>>w;
    a[x-1][y-1]=w;
  }
  // cout<<k;
  a=matrix_power_final(a,k);
  rep(i,0,n-1)
    rep(j,0,n-1)
      c=min(c,a[i][j]);
      // cout<<a[i][j]<<" ";
  if(c>=2e18)cout<<"IMPOSSIBLE";else
  cout<<c;
}
int32_t main()
{
  // ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}