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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n;vvpii v(N,vpii(N));char a[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};char c[4]={'U','L','D','R'};
void dfs(int i,int j,char col){
  if(a[i][j]!='0' or i<1 or i>n or j<1 or j>n)return;
  a[i][j]=col;
  for(int k=0;k<4;k++){
    int X=i+dx[k],Y=j+dy[k];char co=c[k];
    if(v[i][j]==v[X][Y])dfs(X,Y,co);
  }
}
bool f(pii p,pii q,char col1,char col2){
  if(a[p.F][p.S]!='0')
  return 1;
  if(p.F<1 or p.F>n or q.F<1 or q.F>n or p.S<1 or p.S>n or q.S<1 or q.S>n)
    return 0;
  bool ok=0;
  if(v[q.F][q.S]==mp(-1LL,-1LL))ok=1,a[p.F][p.S]=col1;
  if(a[q.F][q.S]=='0' and ok==1)a[q.F][q.S]=col2;
  return ok;
}
void solve(){
  cin>>n;memset(a,'0',sizeof a);
  rep(i,1,n)
    rep(j,1,n){
      cin>>v[i][j].F>>v[i][j].S;
    }
  rep(i,1,n){
    rep(j,1,n){
      if(v[i][j]==mp(i,j))dfs(i,j,'X');
      if(v[i][j]==mp(-1LL,-1LL)){
        int x=0;
        x|=f({i,j},{i-1,j},'U','D');
        x|=f({i,j},{i+1,j},'D','U');
        x|=f({i,j},{i,j-1},'L','R');
        x|=f({i,j},{i,j+1},'R','L');
        if(x==0){cout<<"INVALID";return;}
      }
    }
  }
  rep(i,1,n)
    rep(j,1,n)
      if(a[i][j]=='0'){cout<<"INVALID";return;}
  cout<<"VALID\n";
  rep(i,1,n){
    rep(j,1,n){
      cout<<a[i][j];
    }
    cout<<"\n";
  }
  // Conditions are 
  // {-1,-1} pairs should be forming cycles
  // if v[i][j]=={i,j} place x at {i,j}
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