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
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,a[N][N],o[N][N],t[N][N];vector<vvi> dp(N,vvi(N,vi(2,inf)));
void solve(){
  cin>>n;int zx=-1,zy=-1;
  rep(i,1,n)rep(j,1,n){
    cin>>a[i][j];if(a[i][j]==0){zx=i,zy=j;continue;}
    while((a[i][j]%2)==0)t[i][j]++,a[i][j]/=2;
    while((a[i][j]%5)==0)o[i][j]++,a[i][j]/=5;
  }
  dp[1][1][0]=o[1][1];dp[1][1][1]=t[1][1];
  rep(i,1,n)
    rep(j,1,n){
        if(i==1 and j==1)continue;
        dp[i][j][0]=min(dp[i-1][j][0],dp[i][j-1][0])+o[i][j];
        dp[i][j][1]=min(dp[i-1][j][1],dp[i][j-1][1])+t[i][j];
      }
  int ans=inf;
  if(zx!=-1){
    ans=min(1LL,min(dp[n][n][0],dp[n][n][1]));
  }
  else ans=min(dp[n][n][0],dp[n][n][1]);
  cout<<ans<<"\n";
  if(zx!=-1 and ans==1){
    rep(i,1,zx-1)cout<<"D";
    rep(j,1,zy-1)cout<<"R";
    rep(i,zx,n-1)cout<<"D";
    rep(i,zy,n-1)cout<<"R";
    return;
  }
  stack<char>s;
  int z=0;
  if(min(dp[n][n][0],dp[n][n][1])==dp[n][n][1])z=1;
  int i=n,j=n;
  while(i!=1 or j!=1){
    if(i==1){j--,s.push('R');continue;}
    if(j==1){i--,s.push('D');continue;}
    if((z==0 and dp[i][j][0]==dp[i-1][j][0]+o[i][j]) or (z==1 and dp[i][j][1]==dp[i-1][j][1]+t[i][j]))
      i--,s.push('D');
    else j--,s.push('R');
  }
  while(s.empty()==0)cout<<s.top(),s.pop();
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