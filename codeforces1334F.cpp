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
int n=N,m,t[N];
vi a(n+1),b(n+1),p(n+1),max_possible_b_length(n+1,0),min_possible_b_length(n+1,0),pos(n+1,0),dp(n+1,inf);
//tree should strore min cost for element from l to r
// void build(int a[],int v=1,int tl=1,int tr=n){
//   if(l==r){t[v]=a[l];return;}
//   int tm=tl+tr>>1;
//   build(a,v*2,tl,tm);
//   build(a,v*2+1,tm+1,tr);
//   t[v]=t[v*2]+t[v*2+1];
// }
// int sum(int a[],int l,int r,int v=1,int tl=1,int tr=n){
// }
void add(int l,int r,int val){
  l=max(l,min_possible_b_length[val]);
  r=min(r,max_possible_b_length[val]);
  rep(i,l,r-1){
    dp[i]+=p[val];
  }
}
void solve(){
  cin>>n;
  rep(i,1,n)cin>>a[i];
  rep(i,1,n)cin>>p[i];
  cin>>m;dp[0]=0;
  rep(i,1,m)cin>>b[i],pos[b[i]]=i;
  int j=1;
  rep(i,1,n){
    max_possible_b_length[i]=j;
    if(a[i]==b[j])j++;
  }
  if(j!=m+1){cout<<"NO\n";return;}
  cout<<"YES\n";j--;
  per(i,n,1){
    min_possible_b_length[i]=j;
    if(a[i]==b[j])j--;
  }
  pos[n+1]=m+1;
  per(i,n,1)if(pos[i]==0)pos[i]=pos[i+1];
  rep(i,1,n){
    int j=pos[a[i]];
    if(b[j]==a[i] and p[i]<=0){
      dp[j]=min(dp[j-1],dp[j]+p[i]);
      add(0,j,i);
      add(j+1,m+1,i);
      continue;
    }
    if(b[j]==a[i] and p[i]>0){
      dp[j]=min(dp[j-1],dp[j]);
      add(0,j,i);
      continue;
    }
    add(0,j,i);
    if(p[i]<0)add(j,m+1,i);
  }
  cout<<dp[m];
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