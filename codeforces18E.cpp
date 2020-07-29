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
// #define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<char>;
using vvi = std::vector<vi>;
using v=std::vector<int>;
using vv=std::vector<v>;
using vvv=std::vector<vv>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
void solve(){
  int n,m,cost=inf,ch=inf;cin>>n>>m;vvi a(n+1,vi(m));
  auto dp=vvv(501,vv(26,v(26,inf)));
  dp[0]=vv(26,v(26,0));
  pair<char,char> col[501][26][26];char C1,C2;
  rep(i,1,n)rep(j,0,m-1)cin>>a[i][j];
  rep(row,1,n){
    char tmp;
    rep(c1,'a','z')
      rep(c2,'a','z')
        if(c1!=c2){
          int cost=0;
          rep(col,0,m-1){
            if(col&1)tmp=c2;
            else tmp=c1;
            cost+=(tmp!=a[row][col]);
          }
          rep(l1,'a','z')
            rep(l2,'a','z'){
                if(l1!=c1 and l2!=c2 and l1!=l2)
                  if(dp[row][c1-'a'][c2-'a']>dp[row-1][l1-'a'][l2-'a']+cost)
                    dp[row][c1-'a'][c2-'a']=dp[row-1][l1-'a'][l2-'a']+cost,
                    col[row][c1-'a'][c2-'a']={l1,l2};
                }
          if(ch>dp[row][c1-'a'][c2-'a'] and row==n)ch=dp[row][c1-'a'][c2-'a'],
            C1=c1,C2=c2;
        }
  }
  cout<<ch<<"\n";
  auto f=a;
  per(i,n,1){
    rep(j,0,m-1){
      if(j&1)f[i][j]=C2;
      else f[i][j]=C1;
    }
    char l1=col[i][C1-'a'][C2-'a'].F,l2=col[i][C1-'a'][C2-'a'].S;
    C1=l1,C2=l2;
  }
  rep(i,1,n){rep(j,0,m-1)cout<<f[i][j];cout<<"\n";}
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